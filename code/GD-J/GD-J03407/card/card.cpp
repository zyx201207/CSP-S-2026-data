#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m,a[500001],cnt[300001];
bool flag[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		queue<int> q;
		memset(flag,false,sizeof flag);
		for (int j = i;j <= n;j++)
		{
			if (flag[a[j]]) 
			{
				while (1) 
				{
					if (q.front() == a[j]) break;
					flag[q.front()] = false;
					q.pop();
				}
			}
			else
			{
				q.push(a[j]);
				flag[a[j]] = true;
			} 
		}
		for (int j = 1;j <= m;j++) if (flag[j]) cnt[j]++;
	}
	for (int i = 1;i <= m;i++) cout << cnt[i] << " ";
	return 0;
}
