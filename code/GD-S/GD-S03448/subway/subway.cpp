#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[550];
int a[550][25];
int t[550][25];
int f[550][550][25];
int k[550];
vector<int>l[550];
bool flag=1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)f[i][i][j]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}for(int i=1;i<=m;i++){
		int k1;
		cin>>k1;
		k[i]=k1;
		for(int j=1;j<=k1;j++){
			cin>>a[i][j]>>t[i][j];
			l[a[i][j]].push_back(i);
		}
		for(int j=1;j<=k1;j++){
			for(int h=1;h<=k1;h++){
				f[a[i][j]][a[i][h]][i]=f[a[i][h]][a[i][j]][i]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int h=0;h<(int)l[i].size();h++){
				for(int dian=1;dian<=k[l[i][h]];dian++){
					int zh=a[l[i][h]][dian];
					for(int lu=0;lu<l[zh].size();lu++){
						f[i][j][h]=min(f[i][j][h],f[i][zh][h]+f[zh][j][lu]+t[h][zh]+t[lu][zh]);
					}
				}
			}
		}
	}while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e9;
		for(int i=1;i<=m;i++){
			ans=min(ans,f[x][y][i]);
		}cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
} 
