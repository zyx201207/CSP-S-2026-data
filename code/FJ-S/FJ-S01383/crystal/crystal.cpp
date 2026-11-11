#include<bits/stdc++.h>
using namespace std;
long long n,m,a[511111],b[511111],mm,k=1,maxx=-1,l;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	mm=m;
	for(int i=1;i<=n-1;i++)
	{
		if(mm>=b[i]*k)
		{
			mm=mm-b[i]*k;
			k++;
		}
		else
		{
			l=i;
			break;
		}
	}
	if(l==0)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(k>=maxx)
		{
			maxx=k;
		}
		mm=mm+b[l]-b[i];
		k--;
		for(int j=l;j<=n-1;j++)
		{
			if(mm>=b[j]*k)
			{
				mm=mm-b[j]*k;
				k++;
			}
			else
			{
				l=j;
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
}
