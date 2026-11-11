#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[1005],k[10005],x[1005][1005],u,v,s,minn=1e18;
void dfs(int y,long long s){
	if(y==v) {
		minn=min(minn,s);
		return;
	}
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(x[i][y]!=0) {
				for(int kk=j+1;kk<=k[i];kk++){
					dfs(a[kk],s+1);	
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
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=k[i];i++){
			cin>>u>>v;
			x[i][u]=v;
		}	
	}
	while(q--){
		cin>>u>>v;
		dfs(a[u],1);
		cout<<minn<<"\n";
		minn=1e18;
	}
	return 0;
} 

