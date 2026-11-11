#include<bits/stdc++.h>
const int maxN=2147483647;
typedef long long ll;
using namespace std;
ll g[505][505];
ll con[505];
int w[505];
int c,n,m,d,q;
void build(int now){
	for(int i=1;i<=m;i++){
		if(g[now][i]!=0&&g[now][i]!=0){
			for(int j=1;j<=m;j++){
				if(j!=i&&j!=now&&g[i][j]!=0){
					if(g[now][j]!=0)
						g[j][now]=g[now][j]=min(g[now][j],g[now][i]+g[i][j]);
					else
						g[j][now]=g[now][j]=g[now][i]+g[i][j];
					
//					cout<<"g["<<j<<"]["<<now<<"]="<<g[j][now]<<endl;
//					cout<<"g["<<j<<"]["<<i<<"]="<<g[j][i]<<endl;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long a[500005],b[500005];
	ll k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			con[a[j]]++;
			cin>>b[j];
			
		}
		for(int j=1;j<=k;j++){
			for(int l=j;l<=k;l++){
				
				
				
				
//				cout<<"g["<<a[j]<<"]["<<a[l]<<"]="<<g[a[j]][a[l]]<<endl;
				
				
				
				
				
				if(g[a[j]][a[l]]!=0)
					g[a[j]][a[l]]=g[a[l]][a[j]]=min(g[a[l]][a[j]],b[l]+b[j]);
				else
					g[a[j]][a[l]]=g[a[l]][a[j]]=b[l]+b[j];
				
				
				
				
//				cout<<"g["<<a[j]<<"]["<<a[l]<<"]="<<g[a[j]][a[l]]<<endl;
				
				
				
				
			}
		}
	}
	
	for(int i=1;i<n;i++){
		g[i][i]=0;
	}
	
//	for(int i=1;i<=d&&con[i]!=0;i++){
		build(1);
//	}
	int begin[q+1],arr[q+1];
	for(int i=1;i<=q;i++){
		cin>>begin[i]>>arr[i];
	}
	
	
	
	for(int i=1;i<=q;i++){
		cout<<(g[begin[i]][arr[i]]+w[begin[i]]+w[arr[i]])<<endl;
	}
	return 0;
}

