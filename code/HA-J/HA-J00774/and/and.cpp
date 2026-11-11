#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,l,r) for(ll i=l;i<=r;i++)
#define rfr(i,l,r) for(ll i=l;i>=r;i--)
#define lwq return
bool cmp(ll a,ll b){lwq a>b;}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m,a[200050];
	cin>>n>>m;
	fr(i,1,n)	cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==2){
		ll ans=0;
		fr(i,1,min(n,100LL))
			fr(j,i+1,min(n,100LL))
				ans=max(ans,(a[i]&a[j]));
		cout<<ans;
	}
	else cout<<a[m];
	lwq 0;
}