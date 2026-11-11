#include<bits/stdc++.h>
using namespace std;
int sum,ans,x,y,c,n,m,k[1000],w[1000],a[1000][1000],t[1000][10000],d,q;
void dfs(int nx){
	if(nx==y){
		ans=min(ans,sum);
		sum=w[x]+w[y];
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==nx){
				sum+=w[i];
				for(int l=1;l<=k[i];l++){
					if(nx!=a[i][l]){
						sum+=t[i][l];
						dfs[a[i][l]];
						sum-=t[i][l];
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		sum=w[x]+w[y];
		dfs(x);
		cout<<ans<<endl;
	}
	return 0;
}
 
