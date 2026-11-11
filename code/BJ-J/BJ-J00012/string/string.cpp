#include <bits/stdc++.h>
using namespace std;
struct inf{
	int num;
	char now;
} a[200005];
string s;
int n;
long long ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].now;
	}
	for(int i=1;i<=(n%2?n/2+1:n/2);i++)
	{
		if(a[i].now!=a[n-i+1].now)
		{
		    int there=min(a[i].num, a[n-i+1].num);
		    ans+=there;
		    if(there==a[i].num)
		    {
				a[n-i+1].num-=there;
			}
			else
			{
				a[i].num-=there;
			}
		}
	}
	cout<<ans;
	return 0;
}
