#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,m,a[2000005],vis[5005][5005],ansin=200005,cs;
void dfs(int i,int r,int t){
	if(i==r&&t!=1){
		if(t==ansin) {
			cs++;
		}
		if(t<ansin){
			ansin=t;
			cs=1;
		} 
		
	}
	for(int j=i+1;j<=r;j++){
		if(vis[i][j]==1) dfs(j,r,t+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				if(a[j]-a[i]<=m) vis[i][j]=1;  
			}
		}
		long long ans=0;
		for(long long i=4;i<=n;i++){
			for(long long l=1;l+i-1<=n;l++){
				long long r=l+i-1;
				dfs(l,r,0);
				if(cs==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
