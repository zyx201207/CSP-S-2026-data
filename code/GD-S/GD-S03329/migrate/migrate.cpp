#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int n,d,a[MAXN];
int lst[MAXN],nxt[MAXN],st[MAXN],ed[MAXN];
int f[MAXN],g[MAXN];
inline int lft(int x){
	if(ed[x+1]==0)return 0;
	int L=lst[x+1],R=min(x-1,ed[x+1]);
	if(L>R)return 0;
	if(lst[x]<L||R<lst[x])return (R-L+1);
	return (R-L)+g[lst[x]];
}
inline int rgt(int x){
	if(st[x-1]==n+1)return 0;
	int L=max(x+1,st[x-1]),R=nxt[x-1];
	if(L>R)return 0;
	if(nxt[x]<L||R<nxt[x])return (R-L+1);
	return (R-L)+f[nxt[x]];
}
inline int sol(){
	for(int i=1,now=1;i<=n;i++){
		while(a[i]-a[now]>d)now++;
		lst[i]=now;
	}
	for(int i=n,now=n;i>=1;i--){
		while(a[now]-a[i]>d)now--;
		nxt[i]=now;
	}
	for(int i=1;i<=n;i++)st[i]=n+1,ed[i]=0;
	for(int i=n;i>=1;i--)st[lst[i]]=i;
	for(int i=1;i<=n;i++)ed[nxt[i]]=i;
	for(int i=n;i>=1;i--){
		f[i]=1;
		if(st[i]<=nxt[i]){
			f[i]+=(nxt[i]-st[i])+f[nxt[i]];
		}
	}
	for(int i=1;i<=n;i++){
		g[i]=1;
		if(lst[i]<=ed[i]){
			g[i]+=(ed[i]-lst[i])+g[lst[i]];
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		int x=lft(i),y=rgt(i+1);
		ans+=x*y;
	}
	return ans;
}
int m,b[MAXN];
inline void solve(){
	cin>>m>>d;
	for(int i=1;i<=m;i++)cin>>b[i];
	int ans=0;
	for(int i=1,lst=1;i<=m;i++)if(i==m||b[i+1]-b[i]>d){
		n=i-lst+1;for(int j=lst;j<=i;j++)a[j-lst+1]=b[j];
		lst=i+1;ans+=sol();
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	int c,T;cin>>c>>T;while(T--)solve();
}