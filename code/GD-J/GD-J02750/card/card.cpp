#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=5*1e5+10;
ll n,m;
ll a[maxn];
struct Node{
	bool val;
	ll xb;
}vis[maxn];
ll cnt[maxn];
ll tag[maxn];
bool v[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++) vis[j].val=0;
		for(ll j=1;j<=m;j++) v[j]=0;
		for(ll j=1;j<=n;j++) tag[j]=0;
		for(ll j=i;j<=n;j++){
			if(!vis[a[j]].val){
				vis[a[j]].val=1;
				vis[a[j]].xb=j;
			}
			else{
				tag[vis[a[j]].xb]++;
				tag[j]--;
				vis[a[j]].xb=j;
			}
		}
		for(ll j=i;j<=n;j++){
			tag[j]=tag[j-1]+tag[j];
			if(tag[j]<1) vis[a[j]].val=1;
			else vis[a[j]].val=0;
			if(vis[a[j]].val&&!v[a[j]]){
				cnt[a[j]]++;
				v[a[j]]=1;
			}
		}
	}
	for(ll i=1;i<=m;i++) printf("%lld ",cnt[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
