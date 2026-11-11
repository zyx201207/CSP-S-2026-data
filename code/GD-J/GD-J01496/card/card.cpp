#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define M 300010
int n,m;
int a[N];
int nxt[N],pre[N];
int ed[N];
int lst[M];
int dp[N];
int sum[N];
int ans[M];
void init(){
	memset(sum,0,sizeof(sum));
	memset(ans,0,sizeof(ans));
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	init();
	
	for(int i=1;i<=m;i++)lst[i]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=lst[a[i]];
		pre[lst[a[i]]]=i;
		lst[a[i]]=i;
		
		if(nxt[i]==n+1)ed[i]=i;
		else ed[i]=ed[nxt[i]];
	}
	
	dp[n+1]=n+1;
	for(int i=n;i>=1;i--){
		if(nxt[i]!=n+1)dp[i]=dp[nxt[i]];
		else dp[i]=i;
	}
	
	for(int i=1;i<=n;i++)sum[dp[i]]++;
	
	for(int i=1;i<=n;i++){
		sum[ed[i+1]]+=sum[i];
	}
	
	for(int i=n;i>=1;i--){
		if(!ans[a[i]])ans[a[i]]=sum[i];
	}
	
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';cout<<'\n';
	
	return 0;
}
