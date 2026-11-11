#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n,m;
int a[N];//<=m
int lst[N];
int np[N];int now;
int cnt[N];
int d[M];
void solve1()
{
	for(int i = 1,ttttt; i <= n; i++)
	{
		memset(lst,-1,sizeof(lst));
		np[i - 1] = np[i] = 0;
		now = i - 1;
		for(int j = i; j <= n; j++)
		{
			if(lst[a[j]] == -1)
			{
				np[++now] = a[j];
				lst[a[j]] = now;//
			}
			else
			{
				ttttt = now;
				now = lst[a[j]];
				for(int k = now + 1; k <= ttttt; k++)
				{
					lst[np[k]] = -1;
				}
				lst[a[j]] = now;//
			}
		}
		for(int j = i; j <= now; j++)
		{
			cnt[np[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		cout<<cnt[i]<<" ";
	}
	exit(0);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	bool f = 1;
	for(int i = 1; i < n; i++)
	{
		if(a[i] > a[i + 1]) f = 0;
	}
	if(f)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i = 1; i <= n; i++)
		{
			d[a[i]]++;
		}
		for(int i = n; i >= 1; i -= d[a[i]])
		{
			if(a[i] == a[i + 1] && i != n) continue;
			cnt[a[i]] = i;
		}
		for(int i = 1; i <= m; i++)
		{
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	solve1();
	return 0;
}

