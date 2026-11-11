#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
int a[200005];
int n,m;

int dfs(int need,int last)
{
	if(need==0||last>n)
	{
		return INF;
	}
	int sum=0;
	for(int i=last+1;i<=n;i++)
	{
		int new_sum=dfs(need-1,i)&a[i];
		sum=max(sum,new_sum);
	}
	return sum;
}

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(f==1)
		{
			int j=1;
			while(j<=a[i])
			{
				j*=2;
			}
			if(a[i]+1!=j)
			{
				f=0;
			}
		}
	}
	if(n<=2000)
	{
		cout<<dfs(m,0);
		return 0;
	}
	if(f==1)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	int ans1=INF,ans2=INF;
	for(int i=1;i<=m;i++)
	{
		ans1=ans1&a[i];
	}
	int p=1;
	while(p<=a[1])
	{
		p*=2;
	}
	sort(a+1,a+n+1);
	int id=lower_bound(a+1,a+n+1,p)-a-1-1;
	sort(a+1,a+n+1,cmp);
	for(int i=n-id+1;i<=m;i++)
	{
		ans2=ans2&a[i];
	}
	cout<<max(ans1,ans2);
	return 0;
}
