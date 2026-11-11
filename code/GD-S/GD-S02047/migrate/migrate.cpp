#include <bits/stdc++.h>
#define ll long long
using namespace std;//freopen!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
ll t,n,d,x[20],pos,sl,ans,cnt;
void dfs(int x1, int plc, int sum){
	if(ans>2) return; 
	if(sum>sl) return;
	if(x1==plc){
		++ans;
		return;
	}
	for(int i=n;i>=x1+1;i--){
		if(x[i]-x[x1]<=d) dfs(i,plc,sum+1);
	}
}
void dfs1(int x1, int plc, ll sum){
	if(sum>sl) return;
	if(x1==plc){
		sl=min(sl,sum);
		return;
	}
	for(int i=n;i>=x1+1;i--){
		if(x[i]-x[x1]<=d) dfs1(i,plc,sum+1);
	}
}
void solve(){
	cin>>n>>d, cnt=0;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sl=(1e9), dfs1(i,j,0);
			ans=0, dfs(i,j,0);
			if(ans==2) ++cnt;
		}
	}cout<<cnt<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--) solve();
	return 0;
}
/*

*/
