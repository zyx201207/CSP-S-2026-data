#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
ll n,m,a[maxn],t[maxn];
bool vis[maxn];
stack<ll>st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=1;
				st.push(a[j]);
			}
			else
			{
				while(st.top()!=a[j])
				{
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		ll len=st.size();
		for(int j=1;j<=len;j++)
		{
			t[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
