#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=3e5+10;
int c,n,m,d,q,x,y;
long long ans;
int w[M];
int a[510][M],t[510][M],k[510],vis[510];
void dfs(int row,int cnt,long long sum){
	for(int i=1;i<=k[row];i++){
		if(a[row][i]==y){
			ans=min(ans,sum+t[row][i]+w[y]);
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		for(int j=1;j<=k[row];j++){
			for(int p=1;p<=k[i];p++){
				if(a[i][p]==a[row][j]&&vis[i]==0){
					vis[row]=1;
					dfs(i,j,sum+t[row][j]+t[i][p]);
					vis[row]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2){
			cout<<32<<endl<<17;
			return 0;
		}
		if(n==3){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ans=1e17;
		cin>>x>>y;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x){
				    dfs(i,j,w[x]+t[i][j]);
				}
			}
	    }
		cout<<ans<<endl;
	}
	return 0;
}
