#include<bits/stdc++.h>
using namespace std;

const int N=500+10,M=5e5+10;

long long f[N][N];
int t[N][M];

long long w[M];

vector<int>h[M];

int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(f,0x3f,sizeof(f));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int stk;cin>>stk;
			h[stk].push_back(i);
			cin>>t[i][stk];
		}
	}	
	for(int i=1;i<=m;i++){
		if(h[i].size()<2)continue;
		for(int j=0;j<h[i].size();j++){
			for(int k=j+1;k<h[i].size();k++){
				int cbn=t[h[i][j]][i]+t[h[i][k]][i];
				if(f[h[i][j]][h[i][k]]>cbn){
					f[h[i][j]][h[i][k]]=cbn;
					f[h[i][k]][h[i][j]]=cbn;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		f[i][i]=0; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int i=0;i<h[x].size();i++){
			for(int j=0;j<h[y].size();j++){
				int ti=h[x][i],tj=h[y][j];
				ans=min(t[ti][x]+t[tj][y]+f[ti][tj],ans);
			}		
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
} 


