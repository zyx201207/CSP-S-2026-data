#include<bits/stdc++.h>
using namespace std;
struct sa
{
	long long a;
	char c;
}x[200005],y[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int s=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].c;
	}
	long long sum=x[1].a;
	for(int i=1;i<=n;i++)
	{
		if(i==1) continue;
		if(x[i].c==x[i-1].c)
		{
			sum+=x[i].a;
		}
		if(x[i].c!=x[i-1].c||i==n)
		{
			s++;
			y[s].a=sum;
			y[s].c=x[i-1].c;
			sum=x[i].a;
		}
	}
	if(x[n].c!=x[n-1].c)
	{
		s++;
		y[s].a=x[n].a;
		y[s].c=x[n].c;
	}
	if(s==1)
	{
		cout<<0<<endl;
		return 0;
	}
	int i=1,j=n;
	long long ans=0;
	while(i<j)
	{
		if(y[i].c==y[j].c) 
		{
			if(y[i].a==y[j].a)
			{
				i++;
				j--;
			}
			else if(y[i].a>y[j].a)
			{
				y[i].a-=y[j].a;
				j--;
			}
			else 
			{
				y[j].a-=y[i].a;
				i++;
			}
		}
		else if(y[i].c!=y[j].c) 
		{
			if(y[i].a==y[j].a)
			{
				ans+=y[i].a;
				i++;
				j--;
			}
			else if(y[i].a>y[j].a)
			{
				y[i].a-=y[j].a;
				ans+=y[j].a;
				j--;
			}
			else 
			{
				y[j].a-=y[i].a;
				ans+=y[i].a;
				i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0; 
}
