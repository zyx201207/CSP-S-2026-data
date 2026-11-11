#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int number_1;
	int m;
}a[200005];
int fun1(int x)
{
	int sum_1;
	while(x!=0)
	{
		if(x%2==1)
		{
			sum_1++;
		}
		x/=2;
	}
	return sum_1;
}
bool cmp(Node x,Node y)
{
	if(x.number_1==y.number_1)
		return x.m>y.m;
	return x.number_1>y.number_1;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,t;
	cin>>n>>t;
	if(t == 1)
	{
		int flag = 0;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i].m;
			flag = max(flag,a[i].m);
		}
		cout<<flag;
		return 0;
	}
	if(t==n-1)
	{
		int ans1 = 0,ans2 = 0;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i].m;
		}
		ans1 = a[1].m;
		ans2 = a[2].m;
		for(int i = 2;i<=n-1;i++)
		{
			ans1 = ans1&a[i].m;
			ans2 = ans2&a[i+1].m;
		}
		cout<<max(ans1,ans2);
		return 0;
	}
	if(t==n)
	{
		int ans1 = 0;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i].m;
		}
		ans1 = a[1].m;
		
		for(int i = 2;i<=n;i++)
		{
			ans1 = ans1&a[i].m;
		}
		cout<<ans1;
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i].m;
		a[i].number_1 = fun1(a[i].m);
	}
	sort(a+1,a+n+1,cmp);
	long long ans = a[1].m;
	for(int i = 2;i<=t;i++)
	{
		ans = ans&a[i].m;
	}
	cout<<ans;
	fclose(stdin);	
	fclose(stdout);
	return 0;
}
