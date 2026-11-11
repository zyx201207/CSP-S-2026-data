#include<iostream>
using namespace std;
long long n,m,two[35]={0,1},b[200005],q[200005],len;
string a[200005];
bool f[200005];
string totwo(long long x)
{
	string s="";
	for(long long i=30;i>=1;i--)
	{
		if(x>=two[i])
		{
			x-=two[i];
			s+='1';
		}
		else s+='0';
	}
	return s;
}
int main()
{
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	for(long long i=2;i<=30;i++)
		two[i]=two[i-1]*2;
	cin>>n>>m;
	len=n;
	for(long long i=1;i<=n;i++)
		f[i]=true;
	for(long long i=1;i<=n;i++)
	{
		cin>>q[i];
		a[i]=totwo(q[i]);
	}
	for(long long i=1;i<=30;i++)
	{
		long long ans=0;
		for(long long j=1;j<=n;j++)
			if(a[j][i]=='1'&&f[j])
				ans++;
		if(ans>m)
		{
			for(long long j=1;j<=n;j++)
				if(a[j][i]=='0')
				{
					f[j]=false;
					len-=1;
					if(len==m)
					{
						long long sum=0;
						for(long long j=1;j<=n;j++)
						{
							if(f[j])
							{
								if(sum==0)sum=q[j];
								else sum&=q[j];
							}
						}
						cout<<sum;
						return 0;
					}
				}
		}
		if(ans==m)
		{
			long long sum=0;
			for(long long j=1;j<=n;j++)
			{
				if(a[j][i]=='1')
				{
					if(sum==0)sum=q[j];
					else sum&=q[j];
				}
			}
			cout<<sum;
			return 0;
		}
	}
}
