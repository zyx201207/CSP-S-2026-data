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
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	int k=0;
	cout<<a[m];
	
	
	return 0;
}
//我 结 论 假 了
//我早已麻痹 
//没人觉得最后十五分钟发现结论假了很神圣吗 
