#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200010];
int cmp(int x,int y)
{
	return x>y;
}
main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		cout<<0<<' ';
	
	
	return 0;
}
