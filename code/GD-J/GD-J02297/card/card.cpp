#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+5;
const int MAXM = 3e5+5;

int n,m;
int a[MAXN];
int ret[MAXM];

deque<int>dq;
bool vis[MAXM];

void solve_game(int round)
{
	memset(vis,0,sizeof(vis));
	dq.clear();
	for(int i = round;i <= n;i++)
	{
		if(vis[a[i]]) while(!dq.empty() && dq.back() != a[i])
		{
			vis[dq.back()] = false;
			dq.pop_back();
		}
		else
		{
			dq.push_back(a[i]);
			vis[a[i]] = true;
		}
	}
	bool flag[MAXM];
	for(int i = 1;i <= m;i++) ret[i] += vis[i];
	return;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) solve_game(i);
	for(int i = 1;i <= m;i++) cout << ret[i] <<' ';
}
