#include<bits/stdc++.h>
using namespace std;
long long n=0,p=0,len=0,num=0,cnt=0;
struct xy
{
	long long x;
	char y;
};
xy a[1145140],b[1145140];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x=0;
		char c;
		cin>>x>>c;
		p=p+x;
		a[i].x=x;
		a[i].y=c;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].y==a[i-1].y)
		{
			a[i].x=a[i].x+a[i-1].x;
			a[i-1].x=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].x>0)
		{
			b[++cnt].x=a[i].x;
			len=len+b[cnt].x;
			b[cnt].y=a[i].y;
		}
		if(len>p/2&&num==0)
		{
			num=cnt;
		}
	}
	long long xx=0;
	long long i=1,j=cnt;
	for(;i<j;)
	{
		if(b[i].y==b[j].y)
		{
			if(b[i].x>b[j].x)
			{
				b[i].x=b[i].x-b[j].x;
				b[j].x=0;
				j--;
				continue;
			}
			else if(b[i].x==b[j].x)
			{
				i++;
				j--;
				continue;
			}
			else
			{
				b[j].x=b[j].x-b[i].x;
				b[i].x=0;
				i++;
				continue;
			}
		}
		else
		{
			if(b[i].x>b[j].x)
			{
				b[i].x=b[i].x-b[j].x;
				xx=xx+b[j].x;
				b[j].x=0;
				j--;
			}
			else if(b[i].x==b[j].x)
			{
				xx=xx+b[i].x;
				b[i].x=0;
				b[j].x=0;
				i++;
				j--;
			}
			else
			{
				b[j].x=b[j].x-b[i].x;
				xx=xx+b[i].x;
				b[i].x=0;
				i++;
			}
		}
	}
	cout<<xx;
}
