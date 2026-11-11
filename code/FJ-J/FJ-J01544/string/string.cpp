#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,j,s=0,ans=0,ai=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
		s+=a[i].a;
		ai=max(ai,a[i].a);
	}
	if(n<=10)
	{
		string x="";
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=a[i].a;j++)
				x+=a[i].c;
		}
		if(x.size()%2==0)
		{
			for(i=1;i<=x.size()/2;i++)
			{
				if(x[x.size()/2-i]!=x[x.size()/2+i-1])
					ans++;
			}
			cout<<ans;
		}
		else
		{
			for(i=1;i<=x.size()/2;i++)
			{
				if(x[x.size()/2-i]!=x[x.size()/2+i])
					ans++;
			}
			cout<<ans;
		}
	}
	else
	{
		i=1,j=n;
		while(i!=j-1)
		{
			if(a[i].c!=a[j].c)
				ans+=abs(a[i].a-a[j].a);
			if(a[i].a<a[j].a)
			{
				a[j].a-=a[i].a;
				a[i].a=0;
				i++;
			}
			else
			{
				a[i].a-=a[j].a;
				a[j].a=0;
				j--;
			}
		}
		if(a[i+1].a!=0)
		{
			ans+=a[i+1].a;
		}
		if(a[i-1].a!=0)
		{
			ans+=a[i-1].a;
		}
		if(a[i+2].a!=0)
		{
			ans+=a[i-1].a;
		}
		cout<<ans;
	}
	return 0;
}