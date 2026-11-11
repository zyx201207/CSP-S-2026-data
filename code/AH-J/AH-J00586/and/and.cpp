#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll a[N],b[N],s[N];
ll n,m,c=1,cnt=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		if(a[i-1]==a[i])c++;
		else
		{
			b[++cnt]=c;
			s[cnt]=a[i-1];
			c=1;
		}
	}
	b[++cnt]=c;
	s[cnt]=a[n];
	for(ll i=cnt;i>=1;i--)
	{
		if(m<=b[i])
		{
			cout<<s[i];
			return 0;
		}
		m-=b[i];
	}
}
