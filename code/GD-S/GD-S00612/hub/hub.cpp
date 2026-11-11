#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll fa[200005];
ll dist[10005][10005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ll n,k;
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<=n;i++)	fa[i]=i;
		for(int i=1;i<=n-1;i++){
			ll a,b;
			scanf("%lld%lld",&a,&b);
			dist[a][b]=1;
			dist[b][a]=1;
		}
		cout<<n/k-1<<endl;
	}
	return 0;
}
