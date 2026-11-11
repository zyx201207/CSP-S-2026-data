#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define ls ((cur)<<1)
#define rs ((ls)|1)
const int N=5e5+5;
int n,m,a[N],ans[N],nxt[N],tmp[N],dp[N];
void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=m;i++)tmp[i]=n+1;
	for(int i=n;i>=1;i--){
		nxt[i]=(tmp[a[i]]<=n?tmp[a[i]]:i);
		if(tmp[a[i]]>n)tmp[a[i]]=i;
	}
}
void work(){
	init();
	for(int i=1;i<=n;i++){
		dp[i]+=1;
		dp[nxt[i]+1]+=dp[i];
		ans[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	work();
	return 0;
}
