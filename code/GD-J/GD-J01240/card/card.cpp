#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
const int INF = 1e18;
int n,m;
int a[N];
int vis[300005];
int ans[300005];
int pre[300005];
int nxt[300005];
int cant_use[5003];
void small_solve(){
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=nxt[a[i]],nxt[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) vis[j]=0;
		memset(cant_use,0,sizeof cant_use);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]) cant_use[j]--,cant_use[pre[j]]++;
			else vis[a[j]]=1;
		}
		for(int j=i;j<=n;j++){
			cant_use[j]+=cant_use[j-1];
			if(cant_use[j]==0) ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
void big_solve(){
	for(int i=1;i<=n;i++) cin>>a[i],vis[a[i]]++,pre[i]=nxt[a[i]],nxt[a[i]]=i;
	stack<int> st;
	for(int i=1;i<=n;i++){
		--vis[a[i]];
		while(!st.empty() and vis[a[st.top()]]==0) st.pop();
//		cout<<i<<" add "<<min(i-(st.empty()?0:st.top()),i-pre[i])<<" for "<<a[i]<<"\n";
		if(a[i]!=a[n]) ans[a[i]]+=min(i-(st.empty()?0:st.top()),i-pre[i]);
		st.push(i);
	}
	ans[a[n]]+=n;
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(n<=5000 and m<=3000) small_solve();
	else big_solve();
	return 0;
}
