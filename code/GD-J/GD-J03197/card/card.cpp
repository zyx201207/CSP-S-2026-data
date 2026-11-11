#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],stk[500005],top=0,flag[300005],sum[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=1;j<=m;j++) flag[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]])
			{
				while(top>0&&stk[top]!=a[j])
				{
					flag[stk[top]]=0;
					top--;
				}
			}
			else
			{
				stk[++top]=a[j];
				flag[a[j]]=1;
			}
		}
		for(int j=1;j<=top;j++) sum[stk[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%lld ",sum[i]);
	return 0;
}
