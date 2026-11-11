#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define mp make_pair
#define ls p << 1
#define rs p << 1 | 1
typedef long long ll;
const int N = 2e5 + 5;
int n, m, a[N], sumz[N];
ll z[N][32], ans;
bool vis[N];
//vector<int> now;
void sep(int x)
{
	int cnt = 0;
	ll num = a[x];
	while(num)
	{
		z[x][++cnt] = num % 2;
		num /= 2;
		if(z[x][cnt] == 1) sumz[cnt]++;
	}
}
void check(int step)
{
	if(step == 0) return;
	int si = 0;
	for(int i = step; i >= 1; i--)
	{
		if(sumz[i] >= m)
		{
			si = i;
			break;
		}
	}
	if(!si) return;
	/*queue<int> q;
	for(int i = 0; i < now.size(); i++)
	{
		if(z[now[i]][si] == 0)
		{
			q.push(now[i]);
		}
	}
	while(!q.empty())
	{
		for(int i = si - 1; i >= 1; i--)
		{
			if(z[q.front()][i] == 1) sumz[i]--;
		}
		int pos = lower_bound(now.begin(), now.end(), q.front()) - now.begin();
		now.erase(now.begin() + pos);
		q.pop();
	}*/
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i] && z[i][si] == 0)
		{
			for(int j = si - 1; j >= 1; j--)
				if(z[i][j] == 1) sumz[j]--;
			vis[i] = true;
		}
	}
	ans = ans + (1 << (si - 1));
//	printf("DEBUG! ans=%ld,si=%d\n", ans, si);
	check(si - 1);
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; i++)
	{
		sep(i);
//		now.push_back(i);
	}
	check(31);
	cout << ans << endl;
	return 0;
}
