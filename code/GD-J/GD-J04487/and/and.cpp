#include<bits/stdc++.h>
#define ll long long
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define itn int
#define asn ans
using namespace std;
const ll N=2e5;
ll n,m,ans;
ll a[N];
int main()
{
	fre("and");
	cin>>n>>m;
	cin.tie(nullptr);
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
    return 0;
}
