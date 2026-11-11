#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e5+5;
int n,ans;
struct
{
	int num;
	char ch;
}a[M];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cin>>a[i].num>>a[i].ch;
	}
	int l=1,r=n;
	while (l<r)
	{
		if (a[l].num<a[r].num)
		{
			if (a[l].ch!=a[r].ch) ans+=a[l].num;
			a[r].num-=a[l].num;
			l++;
		}
		else if (a[l].num>a[r].num)
		{
			if (a[l].ch!=a[r].ch) ans+=a[r].num;
			a[l].num-=a[r].num;
			r--;
		}
		else
		{
			if (a[l].ch!=a[r].ch) ans+=a[l].num;
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
