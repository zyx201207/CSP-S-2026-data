#include<bits/stdc++.h>

using namespace std;
int n,m,card[5005],ans[3005];
bool c[3005];
stack <int> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> card[i];
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = i;j < n;j++)
		{
			while(c[card[j]])
			{
				c[st.top()] = 0;
				st.pop();
			}
			st.push(card[j]);
			c[card[j]] = 1;
		}
		while(!st.empty())
		{
			c[st.top()] = 0;
			ans[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
