#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 10;
const int NN = 5e3 + 10;
//n<=2e6
//d<=2e18
//-1e18<=x1<...<xn<=1e18
ll n,d;
ll x[N];
int dp[N];//dp[i]:到i号岛屿的最短长度<=n
int lst[N];//find(x[i] - d)
int find_l,find_r,find_ans,find_mid;
int find(ll t)//x中>=t的最小数的下标
{
	if(x[1] >= t) return 1;
	find_l = 1;
	find_r = n;
	find_ans = n + 1;
	while(find_l <= find_r)
	{
		find_mid = (find_l + find_r) >> 1;
		if(x[find_mid] >= t)
		{
			find_ans = find_mid;
			find_r = find_mid - 1;
		}
		else
		{
			find_l = find_mid + 1;
		}
	}
	return find_ans;
}
ll ans;
int dst[N];
void solve()//O(n)
{
	cin>>n>>d;
	for(int i = 1; i <= n; i++) cin>>x[i];
	for(int i = 1; i <= n; i++) lst[i] = find(x[i] - d);
	ans = 0;
	for(int i = 1,j,k; i < n; i++)
	{
		dp[i] = 0;
		for(j = i + 1; j <= n; j++)
		{
			if(x[j] <= x[i] + d)
			{
				dp[j] = 1;
			}
			else if(x[j] - x[j - 1] > d)
			{
				dp[j] = 1e9;
				for(k = j + 1; k <= n; k++) dp[k] = 1e9;
				break;
			}
			else
			{
				dp[j] = dp[max(i,lst[j])] + 1;
			}
		}
		dst[i] = 1;
		for(j = i + 1; j <= n; j++)
		{
			if(x[j] - x[j - 1] > d) break;
			dst[j] = 0;
			for(k = j - 1; k >= i; k--)
			{
				if(x[j] - x[k] > d) break;
				if(dp[k] + 1 == dp[j])
				{
					dst[j] += dst[k];
				}
			}
			if(dst[j] == 2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
	return;
}
ll gc;//x的差<=2e18 
void solve11()
{
	cin>>n>>d;
	for(int i = 1; i <= n; i++) cin>>x[i];
	if(n == 1 || n == 2)
	{
		cout<<"0\n";
		return;
	}
	gc = d / (x[2] - x[1]);
	if(gc <= 1)
	{
		cout<<"0\n";
		return;
	}
	//j-i=2*gc-1
	cout<<max(0ll,n - 2 * gc + 1)<<endl;
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c == 11 || c == 12)
	{
		while(t--)
		{
			solve11();
		}
		return 0;
	}
	while(t--)
	{
		solve();
	}
	return 0;
}

