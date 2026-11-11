#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,l,r) for(ll i=l;i<=r;i++)
#define rfr(i,l,r) for(ll i=l;i>=r;i--)
#define lwq return
const ll N=5e5+50;
ll n,m,a[N],ans=0;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	fr(i,1,n)	cin>>a[i];
	sort(a+1,a+n+1);
	fr(i,1,n){
		ll l=i,t=m;
		while(true){
			if(l-1==0||a[i]-a[l-1]>t) break;
			l--;t-=a[i]-a[l];
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	lwq 0;
}
