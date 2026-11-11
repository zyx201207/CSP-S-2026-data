#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll n,k,a[N],b[N],c[N];
stack<ll> st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> k;
	for(ll i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(ll i = 1;i <= n;i++)
	{
		memset(b,0,sizeof b);
		for(ll j = i;j <= n;j++)
		{
			if(b[a[j]] == 0)
			{
				b[a[j]]++;
			}
			else
			{
				while(st.top() != a[j])
				{
					b[st.top()]--;
					st.pop();
				}
				st.pop();
			}
			st.push(a[j]);
		}
		while(!st.empty())
		{
			c[st.top()]++;
			st.pop();
		}
	}
	for(ll i = 1;i <= k;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
} 

