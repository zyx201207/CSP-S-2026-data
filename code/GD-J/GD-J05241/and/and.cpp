#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
//		sort(a+1,a+1+n);
		sort(a+1,a+1+n,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=1;i<=m;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=1;i<=m;i++)
	{
		ans=ans&a[i];
	}
		cout<<ans;
	return 0;
}


