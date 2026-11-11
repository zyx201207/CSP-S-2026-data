#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,l,r) for(ll i=l;i<=r;i++)
#define rfr(i,l,r) for(ll i=l;i>=r;i--)
#define lwq return

ll C(ll n){lwq n*(n-1)/2;}

void solve(){
	ll n,d,a[200050],ans=0;
	cin>>n>>d;
	fr(i,1,n)	cin>>a[i];
	fr(i,1,n){
		ll nw=i,t=0;
		fr(j,i+1,n){
			if(abs(a[j]-a[nw])>d){
				ans+=C(t);
				t=0;
				nw=j;
			}
			t++;
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--)	solve();
	lwq 0;
}
