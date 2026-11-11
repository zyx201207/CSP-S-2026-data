#include<bits/stdc++.h>
using namespace std;
int n, m, a[510000], p[15], l[15];
bool b[15];
stack<int> st;
int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]] = true;
	}
	for(int i = 1; i <= n; i++)
	{
		memset(p, 0, sizeof(p));
		for(int j = i; j <= n; j++)
		{
			st.push(a[j]);
			if(p[a[j]] != 0)
			{
				st.pop();
				while(st.top() != a[j])
				{
					p[st.top()]--;
					st.pop();
				}
				p[a[j]] = 1;
			}
			else
			{
				p[a[j]]++;
			}
		}
		for(int i = 1; i <= 9; i++)
		{
			if(p[i] != 0 && b[i] == true)
			{
				l[i]++;
			}
		}
	}
	for(int i = 1; i <= 9; i++)
	{
		if(b[i] == true)
		{
			cout << l[i] << " ";
		}
	}
	return 0;
}
