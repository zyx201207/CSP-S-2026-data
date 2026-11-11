#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+20;
ll n,m,i,j,k,a[N],ans[N],d[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		d[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		vector<ll> v;
		j=i;
		while(j<=n)
		{
			v.push_back(a[j]);
			j=d[a[j]]+1;
		}
		for(j=0;j<v.size();j++)
		{
			ans[v[j]]++;
		}
	}
	for(i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
