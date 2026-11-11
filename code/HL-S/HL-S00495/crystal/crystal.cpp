#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
int main()
{
	freopen("crystal2.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long in = (n+1)/2,m1 = m,ans = 0;
	long long x = a[in];
	while(1)
	{
		if(m1<=0)break;
		int b = a[in]-a[in-1];
		m1-=b;
		a[in-1]=a[in];
		in--;
	}
	for(int i = 1;i<=n;i++)
	{
		if(a[i]==x)ans++;
	}
	cout<<ans;
	return 0;
}  