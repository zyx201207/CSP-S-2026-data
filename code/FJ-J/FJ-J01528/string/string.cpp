#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m,a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<=n;++i)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=m;++i)
	{
		if(i==1)
		{
			ans=a[i];
		}
		else
		{
			ans&=a[i];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
