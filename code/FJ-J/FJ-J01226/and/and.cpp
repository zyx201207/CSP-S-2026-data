#include<bits/stdc++.h>
using namespace std;
struct man
{
	long long a;
	long long a2;
	long long sum;
};
man a[200005];
bool cmp(man x,man y)
{
	if(x.sum!=y.sum) return x.sum>y.sum;
	return x.a>y.a;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a;
		long long a1=a[i].a;
		long long j=0;
		while(a1!=0)
		{
			a[i].a2+=a1%2*pow(10,j);
			a[i].sum+=a1%2;
			j++;
			a1/=2;
		}
	} 
	if(m==1)
	{
		long long maxn=-1;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i].a);
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	long long ans=0;
	for(int i=2;i<=m;i++)
	{
		ans=0;
		for(int j=0;j<a[i-1].sum;j++)
		{
			long long ai1=a[i-1].a2/pow(10,j),ai2=a[i].a2/pow(10,j);
			if(ai1%10==ai2%10&&ai1%10==1)
			{
				ans+=1*pow(10,j);
			}
		}
		a[i].a2=ans;
	}
	long long sum=0,i=0;
	while(ans!=0)
	{
		sum+=ans%10*pow(2,i);
		ans/=10;
		i++;
	}
	cout<<sum;
	return 0;
}
