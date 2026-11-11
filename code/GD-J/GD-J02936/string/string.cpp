#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	long long ans=0,need=a[1],have=a[n];
	while(l<r)
	{
		while(need>0)
		{
			if(need<=have)
			{
				if(c[l]!=c[r])
				{
					ans+=need;
				}
				have-=need;
				need=0;
				break;
			}
			if(c[l]!=c[r])
			{
				ans+=have;
			}
			need-=have;
			r--;
			have=a[r];
		}
		l++;
		need=a[l];
	}
	cout<<ans;
	return 0;
}
