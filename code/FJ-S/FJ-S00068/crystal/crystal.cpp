#include<bits/stdc++.h>
using namespace std;
//注意区分调试语句和运行语句

//awa 
int n;
long long m;
long long a[500005];
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("test.out","w",stdout);
	//务必提交前取消freopen的注释 
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1;
	long long cost=0;
	for(int r=1;r<=n;r++)
	{
		cost+=(r-l)*(a[r]-a[r-1]);
		while(cost>m)
		{
			cost-=(a[r]-a[l++]);
		}
		ans=max(ans,(r-l)+1);
	}
	printf("%d",ans);
	return 0;
}
