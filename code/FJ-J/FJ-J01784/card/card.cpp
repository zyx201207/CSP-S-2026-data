#include<bits/stdc++.h>
#define LL long long
using namespace std;
stack<LL> q;
LL n,m;
LL a[500100];
int v[300100];
LL ans[300100];
void lel(int k)
{
	memset(v,0,sizeof(v));
	v[a[k]]=1;
	q.push(a[k]);
	for(int i=k+1;i<=n;i++)
	{
		if(v[a[i]]) 
		{
			while(q.top()!=a[i])
			{
				v[q.top()]=0;
				q.pop();
			}
		}
		else
		{
			q.push(a[i]);
			v[a[i]]=1;
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		lel(i);
		while(q.size())
		{
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0; 
}
