#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int a[N],cnt[N],ans[N],b[N],c[N],d[N];

stack <int> s;

int n,m;

bool checkA()
{
	for(int i = 2;i <= n;i++)
		if(a[i - 1] > a[i]) return 0;
	return 1;
}

bool checkB()
{
	int cnt = 0;
	for(int i = 2;i <= n;i++)
		if(a[i - 1] != a[i]) cnt++;
	return cnt <= 4999;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(m == 1)
	{
		cout << n << endl;
		return 0; 
	}
	else if(m == 2)
	{
		for(int i = 1;i <= n;i++)
			if(a[i] == a[n]) ans[a[i]]++;
			else ans[1]++,ans[2]++;
		for(int i = 1;i <= m;i++)
		{
			cout << ans[i] << ' ';
		}
		return 0; 
	}
	else if(checkA())
	{
		for(int i = 1;i <= n;i++)
		{
			ans[a[i]] = i;
		}
		for(int i = 1;i <= m;i++)
		{
			cout << ans[i] << ' ';
		}
		return 0;
	}
	else if(checkB())
	{
		int last = a[1],cur = 0,len = 1;
		for(int i = 2;i <= n;i++)
			if(a[i] != last)
			{
				b[++cur] = last;
				c[cur] = len;
				len = 1;
				last = a[i];
			}
			else len++;
		b[++cur] = last;
		c[cur] = len;
		for(int i = 1;i <= cur;i++) 
		{
			for(int j = i;j <= cur;j++)
			{
				d[b[j]] = i;
				if(cnt[b[j]] != 0)
				{
					while(s.size() && s.top() != b[j])
					{
						cnt[s.top()] = 0;
						s.pop();
					}
				}
				else s.push(b[j]),cnt[b[j]] = 1;
			}
			for(int j = 1;j <= m;j++) 
			{
				ans[j] += cnt[j] * c[d[j]];
				cnt[j] = 0;
			}
		} 
		for(int i = 1;i <= m;i++)
		{
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for(int i = 1;i <= n;i++) 
	{
		for(int j = i;j <= n;j++)
			if(cnt[a[j]] != 0)
			{
				while(s.size() && s.top() != a[j])
				{
					cnt[s.top()] = 0;
					s.pop();
				}
			}
			else s.push(a[j]),cnt[a[j]] = 1;
		for(int j = 1;j <= m;j++) 
		{
			ans[j] += cnt[j];
			cnt[j] = 0;
		}
	} 
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
