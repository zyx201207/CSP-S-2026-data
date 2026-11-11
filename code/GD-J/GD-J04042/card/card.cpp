#include<bits/stdc++.h>
using namespace std;
long long N,M;
long long A[500005];
long long where[300005];
long long cnt[300005];
long long Ans[300005];
long long root;
long long c,h[300005],e[1000005][2];

void dfs(int l)
{
	for(int i=h[l];i;i=e[i][0])
	{
//		cout<<l<<" "<<e[i][1]<<endl;
		dfs(e[i][1]);
		Ans[l]+=Ans[e[i][1]];
	}
	Ans[l]+=cnt[l];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&A[i]);
	}
	for(int j=1;j<=M;j++)
	{
		where[j]=0;
	}
	for(int i=1;i<=N;i++)
	{
		where[A[i]]=i;
	}
	root=A[N];
	cnt[A[N]]++;
	for(int i=N-1;i>=1;i--)
	{
		if(where[A[i]]==i)
		{
//			cout<<i<<endl;
			cnt[A[i]]++;
			c++;
			e[c][0]=h[A[i+1]];
			e[c][1]=A[i+1-1];
			h[A[i+1]]=c;
		}
		else
		{
			cnt[A[i]]++;
		}
	}
	dfs(root);
	for(int i=1;i<=M;i++)
	{
		printf("%lld ",Ans[i]);
	}
	return 0;
}
