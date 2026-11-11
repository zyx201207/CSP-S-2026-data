#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t;ll ans=0;
int n;ll d;
int mn;ll cnt;
ll isld[N];
void dfs(int nw,int ed,int step){
	if (nw==ed){
		if (step<mn){
			mn=step;
			cnt=1;
		}else if (step==mn) cnt++;
		return ; 
	}
	for (int i=nw+1;i<=ed;i++){
		if (isld[i]-isld[nw]<=d){
			dfs(i,ed,step+1);
		}
	}
}
void solve(){
	cin>>n>>d;
	ans=0;
	for (int i=1;i<=n;i++) cin>>isld[i];
	for (int i=1;i<=n;i++){
		for (int j=i-1;j>=1;j--){
			mn=N,cnt=0;
			dfs(j,i,0);
			if (cnt==2) ans++;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--) solve();
	
	return 0;
}
