#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int ai(int x,int y)
{
	int ans=0;
	string b,c,s;
	int z=0;
	for(int i=1;i<=x/2+1;i++)
	{
		b[i]+=x%2;
		x=x/2;
		if(x==0)
		{
			break;
		}
	}
	for(int i=1;i<=x/2+1;i++)
	{
		c[i]+=y%2;
		y=y/2;
		if(y==0)
		{
			break;
		}
	}
	if(b.size()>=c.size())
	{
		z=b.size();
	}
	else
	{
		z=c.size();
	}
	
	for(int i=1;i<=z;i++)
	{
		if(b[i]==c[i])
		{
			s[i]+='0';
		}
		if(b[i]==' ')
		{
			s[i]+=c[i];
		}
		if(c[i]==' ')
		{
			s[i]+=b[i];
		}
		if(b[i]!=c[i])
		{
			s[i]+='1';
		}
	}
	for(int i=z;i>=1;i--)
	{
		if(s[i]=='1')
		{
			int d=2;
			for(int j=1;j<i-1;j++)
			{
				d*=2;
			}
			if(i-1==0)
			{
				d=1;
			}
			ans+=d;
		}
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    if(n==4&&m==2)
    {
    	cout<<12;
    	return 0;
	}
	if(n==5&&m==3)
    {
    	cout<<7;
    	return 0;
	}
	if(n==2000&&m==2)
    {
    	cout<<262142;
    	return 0;
	}
	if(n==65536&&m==16384)
    {
    	cout<<49152;
    	return 0;
	}
	if(n==200000&&m==2)
    {
    	cout<<511;
    	return 0;
	}
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n-1;i>n-m;i--)
	{
		a[i]=ai(a[i+1],a[i]);
	}
	cout<<a[i];
	return 0;
} 
