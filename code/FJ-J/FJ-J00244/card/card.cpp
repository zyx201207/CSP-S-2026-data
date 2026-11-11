#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],wm[300005];
int t[300005];
struct sta
{
	int at[500005],op = 0;
	void push(int x)
	{
		at[++op] = x;
	}
	void pop()
	{
		op--;
	}
	int top()
	{
		return at[op];
	}
	int size()
	{
		return op;
	}
	bool empty()
	{
		return op == 0;
	}
	void clear()
	{
		op = 0;
	}
}st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int f = 1;
	while (f <= n)
	{
		memset(t,0,sizeof(t));
		for (int i = f;i <= n;i++)
		{
			if (t[a[i]] == 0)
			{
				t[a[i]]++;
				st.push(a[i]);
			}
			else
			{
				int ti;
				for (int j = 1;j <= n;j++)
				{
					if (st.at[j] == a[i])
					{
						ti = j;
						break;
					}
				}
				while (st.size() >= ti)
				{
					t[st.top()]--;
					st.pop();
				}
				t[a[i]]++;
				st.push(a[i]);
			}
		}
		for (int i = 1;i <= m;i++)
		{
			if (t[i] >= 1)
			{
				wm[i]++;
			}
		}
		f++;
		st.clear();
	}
	for (int i = 1;i <= m;i++)
	{
		cout << wm[i] << " ";
	}
	return 0;
}

