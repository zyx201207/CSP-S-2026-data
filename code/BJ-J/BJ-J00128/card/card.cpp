#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;	
ll n,m;
ll a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<ll>() );
	for(ll i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
