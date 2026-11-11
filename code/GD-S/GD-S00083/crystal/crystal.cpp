#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010];
int main ()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long x=a[2]-a[1];
	long long i=1;
	for(i=1; i>0; i++)
	{
		m-=x*i;
		if(m<0)
		{
			i=i-1;
			break;
		}
		if(m==0)
		{
			break;
		}
	}
	cout<<i+1<<endl;
	return 0;
}
