#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m,a[N];
int ans = -1;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
//	for(int i = 1;i <= n;i++)cout << a[i] << " ";cout << endl; 
	
	int s = a[1],cnt = 1;
	priority_queue<int,vector<int>,greater<int> > q;
	q.push(a[1]);
	for(int i = 2;i <= n;i++)
	{
		while(q.size() * a[i] - s > m && !q.empty())
		{
			s -= q.top();q.pop();
			cnt--;
		}
		if(q.size() * a[i] - s <= m)
		{
			q.push(a[i]);
			cnt++;
			s += a[i];
		}
		ans = max(ans,cnt);
//		cout << cnt << " ";
	}
	cout << ans;
	return 0;
}
