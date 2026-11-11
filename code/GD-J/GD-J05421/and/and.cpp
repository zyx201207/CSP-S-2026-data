#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int a[N];
int f(int x,int num)
{
	int maxn=-1;
	if(num==0)return a[x];
	int ans=a[x];
	for(int i=x+1;i<=n;i++)
	{
		ans=ans&f(i,--num);
		maxn=max(maxn,ans);
	}
	return maxn;
}
int main()
{
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		int sum=a[1];
		for(int i=2;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	cout<<f(1,m);
	return 0;
	
}
