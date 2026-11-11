#include<bits/stdc++.h>
using namespace std;
long long f[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=0,ans=0;
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long a;
		
		cin>>a>>c[i];
		num+=a;
		f[i]=f[i-1]+a;
	}
	if(num%2==1)
	{
		long long i=1,j=num,e=1,g=n;
		for(i,j;i<num/2+1,j>num/2+1;i++,j--)
		{
			if(i>f[e])
			e++;
			if(j<f[g-1])
			g--;
			
			if(c[e]!=c[g])
			{
				ans++;
			}
		}
	}
	else
	{
		long long i=1,j=num,e=1,g=n;
		for(i,j;i<num/2+1,j>=num/2+1;i++,j--)
		{
			if(i>f[e])
			e++;
			cout<<e<<' ';
			if(j<f[g-1])
			g--;
			cout<<g<<'\n';
			if(c[e]!=c[g])
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

