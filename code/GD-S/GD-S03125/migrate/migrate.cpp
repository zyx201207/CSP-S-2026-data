#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll x[N],nxt[N],dp[N][2];
ll n,d;
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	ll l=1;
	for(int i=1;i<=n;i++){
		while(l<n&&x[l+1]-x[i]<=d) l++;
		nxt[i]=l;
		dp[i][0]=dp[i][1]=0;
	}
	dp[n][0]=1;
	ll res=0;
	for(int i=n-1;i>=1;i--){
		dp[i][0]=nxt[i]-i;
		int p=nxt[i],p1=nxt[i]-1,p2=nxt[i]-2;
		if(nxt[p]==nxt[p1]){
			if(nxt[p1]!=nxt[p2]) dp[i][1]+=dp[p][0];
		}
		else if(nxt[p1]==nxt[p2]){
			if(nxt[p1]<p) dp[i][0]+=dp[p][0],dp[i][1]+=dp[nxt[p1]+1][1]+dp[nxt[p1]][0];
			else dp[i][0]+=dp[nxt[p1]+1][0],dp[i][1]+=dp[nxt[p1]+1][1];
		}
		else{
			if(nxt[p1]<p) dp[i][0]+=dp[p][0],dp[i][1]+=dp[p][1]+dp[p1][0];
			else dp[i][0]+=dp[nxt[p1]+1][0],dp[i][1]+=dp[nxt[p2]+1][0]+dp[nxt[p1]+1][1];
		} 
		res+=dp[i][1];
	}
	cout<<res<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T>>T;
	while(T--) solve();
	return 0;
}
