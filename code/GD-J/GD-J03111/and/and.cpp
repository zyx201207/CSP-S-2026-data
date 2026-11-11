#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,ans=INT_MAX;
ll a[N],b[35];
set<ll> s,ss;
bitset<35> bs[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1,x,cnt;i<=n;i++){
		scanf("%lld",&a[i]),x=a[i],cnt=0;
		while(x){
			if(x&1ll)b[cnt]++,bs[i].set(cnt);
			x>>=1ll,cnt++;
		}
	}for(ll i=1;i<=n;i++)s.insert(i),ss.insert(a[i]);
	for(ll i=30;i>=0;i--){
		if(b[i]>=m){
			for(auto &x:s){
				if(!bs[x][i]){
					if(s.count(x))s.erase(x);
					if(ss.count(a[x]))ss.erase(a[x]);
				}
			}if(ss.size()==m)break;
		}
	}for(auto &x:ss)ans&=x;
	printf("%lld",ans);
	return 0;
}

