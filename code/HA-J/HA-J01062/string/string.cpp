#include<bits/stdc++.h>
using namespace std;
struct N{
	long long x;
	char y;
} a[100010];
vector<char> b;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,g,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	g=__gcd(a[1].x,a[2].x);
	for(int i=3;i<=n;i++)
	{
		g=__gcd(a[i].x,g);
	}
	for(int i=1;i<=n;i++)
	{
		a[i].x/=g;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i].x;j++)
		{
			b.push_back(a[i].y);
		}
	}
	int l=0,r=b.size()-1;
	while(l<=r)
	{
		if(b[l]!=b[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans*g;
	return 0;
}
