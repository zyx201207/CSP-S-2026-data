#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],n,m,vis[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		memset(vis,0,sizeof vis);
		stack<int> st;
		for(int i=k;i<=n;i++)
		{
			if(vis[a[i]]==0)
			{
				st.push(a[i]);
				vis[a[i]]=1;
			}
			else
			{
				while(st.size())
				{
					int x=st.top();
					if(x==a[i])
					{
						break;
					}
					else 
					{
						st.pop();
						vis[x]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++) 
		{
			while(st.size())
			{
				int x=st.top();
//				cout<<x<<" ";
				ans[x]++;
				st.pop();
			}
//			cout<<endl;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3

3 1 4

10 3
3 1 2 1 3 2 3 1 2 1

*/
