#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10;
int n,d,pre[N],nxt[N],vis[N],hz[N],a[N],ans; 
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) vis[i]=hz[i]=nxt[i]=0;
	ans=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		int k=upper_bound(a+i,a+n+1,a[i]+d)-a-1;
		if(k<=i||a[k]-d>a[i]) k=0;
		nxt[i]=k;
//		cout<<nxt[i]<<' ';
	}
	for(int i=1;i<n;i++){
		if(vis[i]||(!nxt[i])) continue;
		int x=i,s=0;
		while(nxt[x]){
			pre[nxt[x]]=x;
			x=nxt[x];
			vis[x]=1;
			if(nxt[x-1]==nxt[x]) break;
			s++;
		}
		while(1){
			x=pre[x];
			hz[x]=hz[nxt[x]]+nxt[x]-nxt[x-1];
			if(x==i) break;
		}
	}
	for(int i=1;i<=n;i++) vis[i]=pre[i]=0;
	for(int i=1;i<n;i++){
		if(vis[i]||(!nxt[i])) continue;
		int x=i,s=1;
		while(nxt[x]){
			pre[nxt[x]]=x;
			x=nxt[x];
			if(nxt[x-1]==nxt[x]){
				if(nxt[x-2]!=nxt[x]) ans+=s*(nxt[x]-max(x,nxt[x-2])+hz[nxt[x]]); 
				break;
			}
			s++,vis[x]=1;
		}
//		if(nxt[x-1]==nxt[x]) x=pre[x];
		if(s<3) continue;
		int sum=0;
		x=pre[x];
		while(x!=i){
			sum+=nxt[x-1]-max(x,nxt[x-2]),ans+=sum;
			x=pre[x];
		}
//		cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t>>t;
	while(t--) solve();
	return 0;
}

