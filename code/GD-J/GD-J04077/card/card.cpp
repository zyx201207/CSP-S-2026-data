#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
bool bz[500005];
stack<long long> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=i;j<=n;j++)
		{
			if(bz[a[j]])
			{
				while(st.top()!=a[j])
				{
					bz[st.top()]=0;
					st.pop();
				}
				bz[st.top()]=0;
				st.pop();
			}
			st.push(a[j]);
			bz[a[j]]=1;
		}
		while(st.size()>0)
		{
			ans[st.top()]++;
			st.pop();
		}
		fill(bz,bz+m+1,0);
	}
	for(long long i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
