#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m,sum,t,maxn,l;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	t=1;
	l=1;
	for(int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*t;
		t++;
		while(sum>m)
		{
			t--;
			sum-=a[i]-a[l];
			l++;
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	return 0;
}
