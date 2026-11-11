#include<bits/stdc++.h>
using namespace std;
struct e{
	long long v;
	char x;
}a[200010];
long long n,cnt=0,sum=0,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char last='1';
	for(int i=1;i<=n;i++)
	{
		long long v;
		char x;
		cin>>v>>x;
		sum+=v;
		if(x!=last)
		{
			a[++cnt].v=v;
			a[cnt].x=x;
			last=x;
		}
		else a[cnt].v+=v;
	}
	if(cnt==1)
	{
		cout<<0;
		return 0;
	}
	if(cnt==2)
	{
		cout<<min(a[1].v,a[2].v);
		return 0;
	}
	long long k=0,b;
	for(int i=1;i<=cnt;i++)
	{
		k+=a[i].v;
		if(k>sum/2)
		{
			int d=a[i].v;
			a[i].v=sum/2-(k-d);
			for(int j=cnt;j>i;j--)
			{
				a[j+1].x=a[j].x;
				a[j+1].v=a[j].v;
			}
			a[i+1].x=a[i].x;
			a[i+1].v=d-a[i].v;
			n=cnt+1;
			if(sum%2==1)a[i+1].v--;
			b=i;
			break;
		}
		else if(k==sum/2)
		{
			b=i+1;break;
		}
	}
	int m=n;
	for(int i=1;i<=b;)
	{
		if(a[i].x==a[m].x)
		{
			if(a[i].v>a[m].v)
			{
				a[i].v-=a[m].v;
				m--;
			}
			else if(a[i].v<a[m].v)
			{
				a[m].v-=a[i].v;
				i++;
			}
			else 
			{
				i++;m--;
			}
		}
		else
		{
			if(a[i].v>a[m].v)
			{
				ans+=a[m].v;
				a[i].v-=a[m].v;
				a[m].v=0;m--;
			}
			else if(a[i].v<a[m].v)
			{
				ans+=a[i].v;
				a[m].v-=a[i].v;
				i++;
			}
			else
			{
				i++;m--;
			}
		}
		if(i==m)break;
	}
	cout<<ans;
	return 0;
}
