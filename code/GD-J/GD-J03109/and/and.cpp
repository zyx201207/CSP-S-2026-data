#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n, m;
long long a[N];
bool cmp(int x, int y){
	return x > y;
}
typedef pair<int, int> PII;
vector<PII> s[30];
int vis[N];
vector<int> temp;

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n, cmp);
	for(int i = 1; i <= n; i++)
	{
		vis[i] = 0;
		for(int j = 0; j <= 30; j++)
		{
			if((a[i] & (1 << j))) s[j].push_back({a[i], i});
//			cout << a[i] << " " << (a[i] & (1 << j)) << endl;
		}
	}
	int fl = 0;
	int ans = 0;
	for(int i = 30; i >= 0; i--)
	{
		int cnt = 0;
		temp.clear();
		if(s[i].size() >= m)
		{
			for(PII x : s[i])
			{
				int val = x.first, idx = x.second;
				if(vis[idx] == fl) cnt++, temp.push_back(idx);
			}
		}
		if(cnt >= m)
		{
			fl++;
			for(int x : temp) vis[x] = fl;
			ans += (1 << i);
		}
		
	}
	cout << ans << endl;
}
