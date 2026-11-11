#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int popcount(int x)
{
	int cnt=0;
	int p=1;
	while(p<x)
	{
		cnt+=(x&p);
		p<<=1;
	}
	return cnt;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,[](int x,int y){
		return popcount(x)>popcount(y);
	});
	int ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
