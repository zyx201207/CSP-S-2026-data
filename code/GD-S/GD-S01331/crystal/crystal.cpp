#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll m;
ll num[500005];
ll sum[500005];
int ans;

bool cmp(ll a,ll b)
{
	return a < b;
}

/*
为了保守，选择stl，但为表歉意，归并排序放在此处 

ll as[500005];
void sortt(int l,int r)
{
	if (l == r) return ;
	int tit = (l + r) >> 1;
	sortt(l,tit);
	sortt(tit + 1,r);
	int at = 0;
	int al = l;
	int bl = tit + 1;
	while (al <= tit && bl <= r)
	{
		if (num[al] < num[bl]) as[++ at] = num[al ++];
		else as[++ at] = num[bl ++];
	}
	while (al <= tit) as[++ at] = num[al ++];
	while (bl <= r) as[++ at] = num[bl ++];
	for (int i = 1,j = l;i <= at;i ++,j ++) num[j] = as[i];
	return ;
}*/

int erfen(int x)
{
	int l = 1,r = x;
	while (l < r)
	{
		int tit = (l + r) >> 1;
		if ((x - tit + 1) * num[x] - (sum[x] - sum[tit - 1]) <= m) r = tit;
		else l = tit + 1;
	}
	return l;
}

int main()
{
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> num[i];
	sort(num + 1,num + n + 1,cmp);
	//sortt(1,n);
	for (int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + num[i];
	for (int i = 1;i <= n;i ++)
	{
		int lls = erfen(i);
		ans = max(ans,i - lls + 1);
	}
	cout << ans << endl;
	return 0;
} 

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/

