#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10,M = 5e2+10;
long long a[N],dp[N],qzh[N];
int mxr[N],mnl[N],pre[N],nxt[N],len[N],sz[N];
bool vis[N];
void solve(){
	int n,cnt = 0;
	long long d,ans = 0;
	cin>>n>>d;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		pre[i] = nxt[i] = len[i] = vis[i] = dp[i] = qzh[i] = 0;
	}
	memset(vis,0,sizeof(vis));
	for(int l = 1,r = 1;l<=n;l++){
		while(r<n&&a[r+1]-a[l]<=d){
			r++;
		}
		if(!vis[r]&&l!=r){
			vis[r] = 1;
			nxt[l] = r;
			pre[r] = l;
			len[r] = len[l]+1;
		}
	}
	for(int i = nxt[1]+1;i<=n;i++){
		int p = pre[i];
		if(p+1==i) continue;
		if(pre[p+1])dp[i]+=len[pre[p+1]]+1;
		ans+=dp[i]+qzh[i];
		qzh[i] = qzh[p]+dp[i];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		solve();
	} 
	return 0;
}



