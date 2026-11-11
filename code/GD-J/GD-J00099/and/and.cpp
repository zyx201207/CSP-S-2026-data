#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
long long MAX=0;
long long n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+n+1,cmp);
	MAX=a[1];
	for(int i=2;i<=m;i++)
	{
		MAX=a[i]&MAX;
	}
	cout<<MAX;
	return 0;
}
