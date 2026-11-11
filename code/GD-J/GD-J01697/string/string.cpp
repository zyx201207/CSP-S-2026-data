#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long now=0,cnt=0;
long long ans=0;
struct pp{
	char c;
	long long a;
} a[N],b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].c;
		if(i==1)
		{
			now+=a[i].a;
		}
		else if(i>1&&a[i].c==a[i-1].c)
		{
			now+=a[i].a;
		}
		else if(i>1&&a[i].c!=a[i-1].c)
		{
			b[++cnt].a=now;
			b[cnt].c=a[i-1].c;
			now=a[i].a;
		}
	}
	if(cnt==0)
	{
		cout<<"0";
		return 0;
	}
	else if(cnt!=0)
	{
		b[++cnt].a=now;
		b[cnt].c=a[n].c;
	}
	n=cnt;
	int i=1,j=n;
	while(i<=n&&j>=1&&i<j)
	{
		if(b[i].a<b[j].a)
		{
			if(b[i].c!=b[j].c)
			{
				ans+=b[i].a;
			}
			b[j].a-=b[i].a;
			i++;
		}
		else if(b[i].a==b[j].a)
		{
			if(b[i].c!=b[j].c)
			{
				ans+=b[i].a;
			}
			b[j].a=b[i].a=0;
			i++,j--;
		}
		else if(b[i].a>b[j].a)
		{
			if(b[i].c!=b[j].c)
			{
				ans+=b[j].a; 
			}
			b[i].a-=b[j].a;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
