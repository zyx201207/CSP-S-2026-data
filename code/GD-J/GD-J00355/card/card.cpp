#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
int n,m,card[500010];
int cnt[500010],vis[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++) cin >> card[i];
	for(int i = 1;i<=n;i++)
	{
		stack<int> st;
		for(int j = 1;j<=m;j++) vis[j] = 0;
		for(int j = i;j<=n;j++)
		{
			while(vis[card[j]])
			{
				vis[st.top()] = 0;
				st.pop();
			}
			vis[card[j]] = 1;
			st.push(card[j]);
		}
		for(int j = 1;j<=m;j++) if(vis[j]) cnt[j]++;
	}
	for(int i = 1;i<=m;i++) cout << cnt[i] <<" ";
	return 0;
} 
