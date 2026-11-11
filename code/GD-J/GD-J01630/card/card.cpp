#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
ll a[500005];
bool hav[500005];
ll cnt[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int x = 1;x <= n;x++)
	{
		stack<ll>st;
		memset(hav,0,sizeof(hav));
		for(int i = x;i <= n;i++)
		{
			if(hav[a[i]] == false)
			{
				st.push(a[i]);
				hav[a[i]] = true;
			}
			else
			{
				while(hav[a[i]] == true && st.empty() == false)
				{
					hav[st.top()] = false;
					st.pop();
				}
				st.push(a[i]);
			}
		}
		while(!st.empty())
		{
			//cout << st.top() << " ";
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << cnt[i] << ' ';
	}
	
	return 0;
}
