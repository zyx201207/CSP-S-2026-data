#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=1e6;
long long a[N];
long long b[N];
long long ans;
long long s=2;
long long f=0;
long long u=0;
long long ta;
long long d(int h)
{
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for (int i=2;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int h=2,t=1;
	f=a[2]-a[1];
	for (int i=3;i<=n;i++)
	{
		u=a[i]-a[h];
		if(s*u<=(m-f))
		{
			f+=(h-t)*u;
			h++;
			s++;
		}
		else
		{
			f-=(a[h]-a[t]);
			s--;
			t++;
		}
		ta=max(ta,s);
	}
	cout<<ta;
	return 0;
}
