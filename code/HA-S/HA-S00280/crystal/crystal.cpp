#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500005];
long long sum;
long long cha[500005];
long long qcha[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++)
	{
		cha[i]=a[i]-a[i-1];
		qcha[i]=qcha[i-1]+cha[i];
	}
	long long head=1,tail=0;
	long long num=qcha[1]; 
	while(tail<=n)
	{
		long long q;
		if(tail<=head)
		{
			tail++;
		}
		else
		{
			if((num+(cha[tail]*(tail-head)))<=m)
			{
				num+=(cha[tail]*(tail-head));
				q=tail-head+1;
				sum=max(sum,q);
				tail++;
			}
			else
			{
				tail--;
				num-=(a[tail]-a[head]);
				head++;
			}
		}
	}
	cout<<sum;
	return 0;
}
