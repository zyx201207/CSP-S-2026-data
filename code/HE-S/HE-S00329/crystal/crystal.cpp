#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long m,a[N];
int n,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;
	long long lst=0;
	for (int i=1;i<=n;i++)
	{
		lst+=(a[i]-a[i-1])*(i-j);
		while (j<i)
		{
			if (lst>m)
			{
				j++;
				lst-=(a[i]-a[j]);
			}
			else break;
		}
		ans=max(ans,i-j+1);
	} 
	cout<<ans;
	return 0;
}
