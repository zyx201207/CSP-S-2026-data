#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=200010;
ll a[maxn];
ll d[20010][2010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	d[1][1]=a[1];
	for(ll i=2;i<=n;i++){
		d[i][1]=a[i];
		for(ll j=2;j<=m;j++){
			for(ll k=1;k<i;k++){
				d[i][j]=max(d[i][j],max(d[k][j],(d[k][j-1]&a[i])));
			}
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans=max(ans,d[i][m]);
	}
	cout<<ans;
	return 0;
}
