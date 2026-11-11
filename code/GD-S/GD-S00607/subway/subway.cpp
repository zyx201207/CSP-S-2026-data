#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll c,n,m,d,q;
ll w[N];
struct p{
	ll a,t;
}k[501][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	while(q--){
		ll x,y,ans=w[x]+w[y];
		scanf("%lld%lld",&x,&y);
		cout<<ans<<" ";
	}
	return 0;
} 
