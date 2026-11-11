#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
int a[N],res;
int build_in_popcount(int k)
{
	int t=__lg(k)+1;
	int re=0;
	vector<bool> vec(t);
	int top=0;
	while(k)
	{
		top++;
		vec[top]=k%2;
		k/=2;
	}
	for (int i=1;i<=top;i++)
	{
		if(vec[i])re++;
	}
	return re;
}
bool cmp(int a,int b)
{
	return a>b;
}
bool cmp2(int a,int b)
{
	return (build_in_popcount(a)!=build_in_popcount(b))?(build_in_popcount(a)>build_in_popcount(b)):(a>b);
}
int solve()
{
	sort(a+1,a+n+1,cmp2);
	int iso=0,ans=0;
	for (int i=1;i<=m;i++)
	{
		if(iso==0)ans=a[i];
		ans&a[i];
	}
	return ans;
}
int main()
{
	bool flag=1;
	bool flag2=1;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(__lg(a[i]+1)!=__lg(a[i])+1)flag=0;
		if(a[i]!=i-1)flag2=0;
	}
	if(flag)
	{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	int f=solve();
	int iso=0;
	int ans=0;
	for (int i=1;i<1e5;i++)
	{
		if(build_in_popcount(i)!=m)
			continue;
		for (int j=0;j<__lg(n);j++)
		{
			if(iso==0)ans=a[i];
			if(i&(1<<j))
			{
				ans&=a[i];
				iso++;
			}
		}
		res=max(res,ans);
	}
	cout<<max(res,f);
	return 0;
}
