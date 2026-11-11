#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define int long long
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f3f;
int n,m,a[N],cf[N],sum[N];
bool flag = 1,flag2 = 1; 
bool cmp(int x,int y)
{
	return x > y;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int ch;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != i)
			flag = 0;
		if(i == 2)
			ch = a[i] - a[i -1];
		else if(i > 2 && a[i] - a[i - 1] != ch)
			flag2 = 0;
	}
	if(flag)
	{
		double x1 = sqrt(m * 1.0 + 0.25) - 0.5;
		//cout << x1 << endl;
		int ans = x1;
		int cha = m - ans * (ans + 1);
		
		if(cha >= ans + 1)
			ans = ans * 2 + 1;
		else
			ans *= 2;
		cout << ans + 1 << endl;
		return 0;
	}
	if(flag2)
	{
		double x1 = sqrt(m * 1.0 / ch + 0.25) - 0.5;
		int ans = x1;
		int cha = m - ch * ans * (ans + 1);
		
		if(cha >= (ans+1) * ch)
			ans = ans * 2 + 1;
		else
			ans *= 2;
		cout << ans + 1 << endl;
		return 0;
	}
	sort(a + 1,a + n + 1);
	int maxn = -1;
	for(int i = 1;i <= n;i++)
	{
		int kk = m,ans = 0;
		for(int j = i;j >= 1;j--)
		{
			int cha = a[i] - a[j];
			if(cha <= kk)
			{
				kk -= cha;
				ans++;
			}
			else
				break;
		}
		maxn = max(maxn,ans);
	}
	cout << maxn << endl;
	return 0;
}
