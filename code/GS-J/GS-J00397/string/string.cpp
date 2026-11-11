#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n,h,t,sm,sum;
	sum=0;
	cin>>n;
	h=1;
	t=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	while(h<t)
	{
		sm=min(a[h],a[t]);
		a[h]=a[h]-sm;
		a[t]=a[t]-sm;
		if(c[h]!=c[t])
		{
			sum=sum+sm;
		}
		if(a[h]==0)
		{
			h++;
		}
		if(a[t]==0)
		{
			t--;
		}
	}
	cout<<sum;
	return 0;
 } 
