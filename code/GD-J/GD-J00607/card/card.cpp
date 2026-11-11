#include<bits/stdc++.h>
#define N 100010
#define int long long 
using namespace std;
int n,m,a[N];
stack<int> st;
/*
dp[i] 表示第i张牌在桌面留存的局数

dp[i]
 
*/
int fg[N],ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) //模拟第i局的情况 
	{
		for(int i=1;i<=n;i++) //模拟牌a[i]
		{
			if(fg[a[i]]) //当前场上有a[i] 
			{
				int pre=st.size();
				while(!st.empty()&&fg[st.top()]&&st.top()!=a[i]) 
				{
					fg[st.top()]--;
					if(st.top()!=a[i]) ans[st.top()]+=pre-st.size();
					st.pop();
				}
			}
			else fg[a[i]]++,st.push(a[i]);
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
} 
