#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
int a;
char c;
}b[200005];
char l=' ';
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a>>b[i].c;
		cnt+=b[i].a;
	}
	long long x=0;
	for(int i=0;x<cnt/2;i++)
	{
		x+=b[i].a;
		m=i;
	}
	n++;
	for(int i=n;i>m+1;i--)
	{
		b[i]=b[i-1];
	}
	b[m+1].a=x-cnt/2;
	b[m+1].c=b[m].c;
	b[m].a=-x+b[m].a+cnt/2;
	int l=1,r=n;
	while(l<r)
	{
		if(b[l].a==0)
		{
			l++;
		}
		if(b[r].a==0)
		{
			r--;
		}
		if(b[l].c!=b[r].c)
		{
			ans+=min(b[l].a,b[r].a);
			if(b[l].a>=b[r].a)
			{
				b[l].a-=b[r].a;
				b[r].a=0;
			}
			if(b[l].a<b[r].a)
			{
				b[r].a-=b[l].a;
				b[l].a=0;
			}
		}
		else
		{
			if(b[l].a>=b[r].a)
			{
				b[l].a-=b[r].a;
				b[r].a=0;
			}
			if(b[l].a<b[r].a)
			{
				b[r].a-=b[l].a;
				b[l].a=0;
			}
		}
		if(b[l].a==0)
		{
			l++;
		}
		if(b[r].a==0)
		{
			r--;
		}
	}
	cout<<ans;
	return 0;
}
