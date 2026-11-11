#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long bh,num;
};
long long n,m,a[500005],ans[500005],lst[500005],wh[500005],cnt[500005],tot;
vector<node>E[500005];
long long dfs(long long u,long long f)
{
	if(E[u].empty())
	{
		ans[f]+=cnt[u];
		return cnt[u];
	}
	long long sum=cnt[u];
	for(auto i:E[u])
	{
		long long v=i.bh,numb=i.num;
		sum+=dfs(v,numb);
	}
	ans[f]+=sum;
	return sum;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=n;i>=1;i--)
	{
		if(!lst[a[i]])
		{
			E[wh[i+1]].push_back({++tot,a[i]});
			wh[i]=tot;
			cnt[wh[i]]++;
		}
		else
		{
			wh[i]=wh[lst[a[i]]];
			cnt[wh[i]]++;
		}
		lst[a[i]]=i;
	}
	dfs(0,0); 
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}
