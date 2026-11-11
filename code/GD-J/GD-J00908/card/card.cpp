#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],ans,t[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i],t[a[i]]++;
	ll p;
	for(ll i=n;i>=1;i--)
	{
		p=i;
		if(t[a[p]]>=2) break;
		t[a[p]]=p;
	}
	t[a[p]]=p;
	if(!p)
	{
		for(ll i=1;i<=m;i++) cout<<n<<' ';
		return 0;
	}
	for(ll i=1;i<=m;i++) cout<<t[i]<<' ';
	return 0;
}
