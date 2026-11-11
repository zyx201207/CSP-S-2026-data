#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for(ll i=a;i<=n;++i)
const int maxn=2e5+10;
ll n,m,a[maxn],ans;
void sol()
{
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n,greater<ll>());
	if(a[m-1]%a[m]==0)cout<<a[m+m];
	else cout<<a[1];
}
int main()
{
	sol();
	return 0;
}
