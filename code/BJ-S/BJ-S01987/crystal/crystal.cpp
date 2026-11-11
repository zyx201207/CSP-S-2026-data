#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll innum=0,ans=0;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		m-=innum*(a[i]-a[i-1]);
		if(m<0)
		{
			m+=a[i]-a[i-innum];
			innum--;
		}
		innum++;
		ans=max(ans,innum);
	}
	cout<<ans<<'\n';
	return 0;
}