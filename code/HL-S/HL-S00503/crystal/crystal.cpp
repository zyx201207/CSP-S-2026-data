#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
ll n,m,a[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(abs(a[i]-a[n/2+n%2])<=m)
		{
			ans++;
			m-=abs(a[i]-a[n/2+n%2]);
		}
	}
	cout<<ans;
	return 0;
}