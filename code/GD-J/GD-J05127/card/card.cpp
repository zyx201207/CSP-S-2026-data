#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005],b[300005];
stack<long long> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				st.push(a[j]);
				b[a[j]]=1;
			}
			else
			{
				while(st.top()!=a[j])
				{
					b[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}
