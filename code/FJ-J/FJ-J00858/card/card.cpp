#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],t[300005];
stack <int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++) t[j] = 0;
		for(int j = i;j <= n;j++)
		{
			if(!t[a[j]])
			{
				s.push(a[j]);
				t[a[j]]++;
			}
			else
			{
				while(s.top() != a[j])
				{
					t[s.top()]--;
					s.pop();
				}
				s.pop();
				s.push(a[j]);
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
