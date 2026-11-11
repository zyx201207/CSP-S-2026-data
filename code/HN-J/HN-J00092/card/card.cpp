#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 5;
int n, m;
int a[N], ans[N], tong[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(tong, 0, sizeof(tong));
		queue<int> q, qq;
		for (int j = i; j <= n; j++)
		{
			if ( tong[a[j]] == 0 )
			{
				q.push(a[j]);
				tong[a[j]]++;
			}
			else
			{
				int p = q.size();
				for (int k = 1; k <= p; k++)
				{
					if ( q.front() == a[j] )
					{
						while(!q.empty())q.pop();
						break;
					}
					else
					{
						qq.push(q.front());
						q.pop();
					}
				} 
				p = qq.size();
				for (int k = 1; k <= p; k++)
				{
					q.push(qq.front());
					qq.pop();
				}
				q.push(a[j]);
			}
		}
		int p = q.size();
		for (int k = 1; k <= p; k++)
		{
			ans[q.front()]++;
			q.pop();
		}
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	cout<< endl;
	return 0;
}
