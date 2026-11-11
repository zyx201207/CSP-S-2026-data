#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct node{
	int num, two;
};

int n, m, maxn = 0;
node a[MAXN];

int shu(int cnt)
{
	int ss = 0;
	while (cnt != 0)
	{
		if(cnt % 2 == 1)  ss++;
		cnt /= 2;
	}
	return ss;

}

bool cmp(node x,node y)
{
	return x.two > y.two;
}

void dfs(int t, int last, int total) //表示当前已经选的长度 
{
	if(t == m)
	{
		maxn = max(maxn, total);
		return ;
	}
	for(int i = last + 1; i <= n - (m - t) + 1; i++)
	{
		int s = total&a[i].num;
		if(s > maxn)
		{
			dfs(t + 1, i, s);
		}
	}
}

int main()
{
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i].num;
		a[i].two = shu(a[i].num);
	}
	
	sort(a + 1, a + n + 1, cmp);
	
	for(int i = 1; i <= n - m + 1; i++)
	{
		dfs(1 ,i, a[i].num);
	}
	
	cout << maxn;
	return 0;
}
