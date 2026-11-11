#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],f[1000000],ans[50],flag,b[50],c,s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	b[0]=1;
	for(int i=1;i<30;i++)
		b[i]=b[i-1]*2;
	for(int i=29;i>=0;i--)
	{
		c=0;
		for(int j=1;j<=n;j++)
		{
			if((a[j]&b[i])!=0 && flag==0)
				c++;
			if((a[j]&b[i])!=0 && flag==1 && f[j]==1)
				c++;
		}
		if(c>=m)
		{
			if(flag==0)
			{
				for(int j=1;j<=n;j++)
					if((a[j]&b[i])!=0)
						f[j]=1;
				flag=1,ans[i]=1;
			}
			else
			{
				for(int j=1;j<=n;j++)
					if((a[j]&b[i])==0 && f[j]==1)
						f[j]=0;
				ans[i]=1;
			}
		}
	}
	for(int i=0;i<=29;i++)
		if(ans[i])
			s+=b[i];
	cout<<s;
	
	return 0;
}
