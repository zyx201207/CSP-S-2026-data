#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m,p,i,j,maxn=INT_MIN,sum=1,t;
	bool flag=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	t=a[2]-a[1];
	for(i=2;i<n;i++)
	{
		if(t!=a[i+1]-a[i])
		{
			flag=1;
		}
		t=a[i+1]-a[i];
	}
	if(flag==0&&t!=0)
	{
		cout<<m/t;
		return 0;
	}
	if(flag==0&&t==0)
	{
		cout<<n;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		sum=1;
		p=m;
		for(j=i-1;j>=1;j--)
		{
			if(a[i]-a[j]<=p)
			{
				p-=a[i]-a[j];
				sum++;
			}
			else
			{
				break;
			}
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
}
