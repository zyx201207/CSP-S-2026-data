#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
long long a1,a2;
long long n,m,trueans,a[1000001],num[1000001],ans[1000001],w[1000001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		num[i]=1;
		while(a[i]!=0)
		{
			num[i]=num[i]*10+a[i]%2;
			a[i]/=2;
		}
		while(num[i]!=1)
		{
			ans[i]=ans[i]*10+num[i]%10;
			num[i]/=10;
		}
	}
	for(int i=1;i<=n-1;i++)
		for(int j=i+1;j<=n;j++)
		{
			a1=ans[i],a2=ans[j];
			while(min(a1,a2))
			{
				if(a1%10==1 && a2%10==1)
					w[i]=w[i]*10+1;
				else
					w[i]=w[i]*10;
				a1/=10,a2/=10;
			}
			long long cs=1,bj=w[i]%10*1;
			w[i]/=10;
			while(w[i])
			{
				long long lj=1;
				for(int q=1;q<=cs;q++)
					lj*=2;
				bj+=lj*(w[i]%10);
				w[i]/=10;
			}
			trueans=max(trueans,bj);
		}
	cout<<trueans;
	return 0;
}
