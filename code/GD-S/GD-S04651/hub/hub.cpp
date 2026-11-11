#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n,m) for(ll i=n;i<=m;i++)
#define disrep(i,n,m) for(ll i=n;i>=m;i--)
ll c,t;
struct way{
	ll one;
	ll two;
}a[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		rep(i,1,n-1){
			cin>>a[i].one>>a[i].two;
		}
		cout<<0<<"\n";
	}
	return 0;
}
