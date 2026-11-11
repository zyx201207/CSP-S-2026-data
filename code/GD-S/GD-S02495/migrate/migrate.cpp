#include<iostream>
#define int long long
using namespace std;
int c,t,n,d,a[2000005],mn,cnt;
void dfs(int b,int e,int s){
	if(b==e){
		if(s<mn){
			mn=s;
			cnt=1;
		}
		else if(s==mn){
			cnt++;
		}
		return;
	}
	for(int i=b+1;i<=e;i++){
		if(a[b]+d<a[i]) break;
		dfs(i,e,s+1);
	}
}
void work(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mn=1e18;
			cnt=0;
			dfs(i,j,0);
			if(cnt==2) ans++;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		work();
	}
	return 0;
}
