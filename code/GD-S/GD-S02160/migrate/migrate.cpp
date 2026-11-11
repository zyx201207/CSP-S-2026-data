#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
int n;
ll ans,d,x[N];
queue <vector <int>> q;
void Inputtt()
{
	cin >> n >> d;
	for(int i = 1;i <= n;i++)
		cin >> x[i];
}
void Solve_11_to_12()
{
	ll y = x[2] - x[1];
	int t = d / y;
	if(t <= 1 || n == 2)
		cout << "0\n";
	else
	{
		t = (t << 1) - 1;
		cout << max(0,n - t) << '\n';
	}
}
bool check(int st,int ed)
{
	int stp = 0,tot = 0;
	while(!q.empty())
		q.pop();
	vector <int> tmp;
	tmp.push_back(st);
	q.push(tmp);
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		int len = tmp.size(),edd = tmp[len - 1];
		if(edd == ed)
		{
			if(!stp)
				stp = len,tot++;
			else
			{
				if(len > stp)
					continue;
				tot++;
				if(tot > 2)
					return false;
			}
		}
		for(int i = edd + 1;i <= ed;i++)
		{
			if(x[i] - x[edd] <= d)
			{
				tmp.push_back(i);
				q.push(tmp);
				tmp.pop_back();
			}
			else
				break;
		}
	}
	return tot == 2;
}
void Solve()
{
	ans = 0;
	for(int i = 1;i < n;i++)
		for(int j = i + 1;j <= n;j++)
			if(check(i,j))
				ans++;
	cout << ans << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--)
	{
		Inputtt();
		if(11 <= c && c <= 12)
			Solve_11_to_12();
		else
			Solve();
	}
	return 0;
}

