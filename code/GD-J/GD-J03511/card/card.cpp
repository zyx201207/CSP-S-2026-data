#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],lst[N],nxt[N],rt[N],dp[N],ans[N];
int n,m;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		nxt[i]=lst[a[i]];
		lst[a[i]]=i;
		if(nxt[i]) rt[i]=rt[nxt[i]];
		else rt[i]=i;
		dp[rt[i]]++;
	}
	for(int i=1;i<=n;i++) 
		if(nxt[i]) dp[rt[nxt[i]]]+=dp[i];
		else dp[rt[i+1]]+=dp[i];
	for(int i=n;i>=1;i--)
		if(!ans[a[i]]) ans[a[i]]=dp[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	cout<<'\n';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	while(T--) solve();
	return 0;
}
