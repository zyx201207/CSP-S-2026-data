#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000001];
int dfs(int x,int y,int d){
	if(x==y) return 1;
	long long ans=0;
	for(int i=x+1;i<=y&&a[x]+d>=a[i];i++){
		ans+=dfs(i,y,d);
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dfs(i,j,d)==3) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
