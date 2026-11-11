#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x,ans,a[N],nxt[N],vis[N],p1[N],p2[N],s1[N],s2[N],lst[N];
bool flag;
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		if(i>2&&a[nxt[i]]-a[i-2]<=d) vis[i]=2;
		else if(i>1&&a[nxt[i]]-a[i-1]<=d) vis[i]=1;
		else vis[i]=0;
	}
	ans=0;
	for(int i=2;i<=n;i++){
		p1[i]=min(nxt[i-1],nxt[i]-1)-max(nxt[i-2],i);
		p2[i]=nxt[i]-nxt[i-1];
	}
	for(int i=n;i>=1;i--){
		if(i==nxt[i]){
			s1[i]=0;
			s2[i]=1;
			continue;
		}
		if(vis[nxt[i]]==0){
			if(i>1&&a[nxt[i]-1]-a[i-1]<=d){
				s1[i]=s1[nxt[i]];
				ans+=p1[nxt[i]];
			}
			else s1[i]=s1[nxt[i]]+p1[nxt[i]];
			s2[i]=s2[nxt[i]]+p2[nxt[i]];
		}
		else if(vis[nxt[i]]==1){
			if(i>1&&a[nxt[i]-1]-a[i-1]<=d){
				s1[i]=0;
				ans+=p1[nxt[i]];
			}
			else s1[i]=p1[nxt[i]];
			s2[i]=1;
		}
		else{
			s1[i]=0;
			s2[i]=1;
		}
	}
	for(int i=n;i>=1;i--){
		if(i==nxt[i]){
			lst[i]=0;
			continue;
		}
		if(vis[nxt[i]]==0) lst[i]=lst[nxt[i]];
		else if(vis[nxt[i]]==1){
			if(i>1&&a[nxt[i]-1]-a[i-1]<=d){
				lst[i]=0;
				ans+=s2[nxt[i]];
			}
			else lst[i]=nxt[i];
		}
		else lst[i]=0;
	}
	for(int i=1;i<=n;i++) ans+=s1[i]+s2[lst[i]];
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) solve();
	return 0;
}
