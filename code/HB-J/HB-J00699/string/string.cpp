#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
struct node
{
	int sum;
	char ch;
};
node a[N];
int n;
int ans = 0;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].sum >> a[i].ch;
	}
	char cmp = a[1].ch;
	bool flag = false;
	for(int i = 2; i <= n; i++)
	{
		if(a[i].ch != cmp) 
		{
			flag = true;
			break;
		}
	}
	if(!flag)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n / 2; i++)
	{
		int p = i + n - 1;
		if(a[i].ch == a[p].ch) ans += abs(a[i].sum - a[p].sum);
		else ans += max(a[i].sum , a[p].sum);
	}
	cout << ans;
	return 0;
}
