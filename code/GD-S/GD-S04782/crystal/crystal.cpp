#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long n,m,a[500005],ans,b[500005],sum=-2147483647;
bool k;
int maxn(int x,int y)
{
	if(x>y)return x;
	return y;
}
int rather(long long m)
{
	int i=1,ans=1;
	while(1)
	{
		if(m-2*i<0)
		{
			if(m-i>=0)
				++ans;
			return ans;
		}
		m-=2*i;
		++i;
		ans+=2;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) k=1;
	}
	if(m==0)	{
		cout<<1;
		return 0;
	}
	if(k==0)
	{
		if(m==1)cout<<2;
		else
			cout<<rather(m);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(i!=1)
			b[i-1]=a[i]-a[i-1];
	for(int i=1;i<=n-1;i++)
	{
		int o=0,w=0;
		for(int j=i;j<=n-1;j++)
		{
			
			o+=b[j];
			m-=o;
			w++;
			if(m<0)
			{
				if(b[j]!=0)
					--w;
				j=n-1;
			}
			else if(m==0)j=n-1;
		}
		sum=maxn(sum,w);
	}
	cout<<sum+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
