#include <bits/stdc++.h>
using namespace std;
long long w[200005];
//地铁口到站厅的时间 
long long a[20005][20005];
//第i条路径经过的第j个地铁站 
long long t[20005][20005];
//从该地铁站的站厅走到第i条线路的站台需要的时间 
long long k[200005]; 
long long n;
long long moved(long long start,long long ending,long long from)
{
	bool start_is_in_line = false,ending_is_in_line = false;
	//在相同的一个线路上 
	for(long long i = 0;i < n;i++)
	{
		for(long long j = 0;j < k[i];j++)
		{
			if(start == a[i][j])
			{
				start_is_in_line = true;
			}
		}
		for(long long j = 0;j < k[i];j++)
		{
			if(ending == a[i][j])
			{
				ending_is_in_line = true;
			}
		}
		if(start_is_in_line && ending_is_in_line)
		{
			return w[start] + w[ending];
		}
	}
	//不在相同的一个线路上 
	for(long long i = 0;i < n;i++)
	{
		for(long long j = 0;j < k[i];j++)
		{
			if(start = a[i][j])
			{
				return w[start] + min(moved(a[i][j+1],end,start),moved(a[i][j+1],end,start),);
			} 
		}
	}
	return 404;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,m,d,q,start,ending;
	long long ans = 0;
	cin >> c;
	cin >> n >> m >> d >> q;
	for(long long i = 0;i < m;i++)
	{
		cin >> w[i];
	}
	for(long long i = 0;i < n;i++)
	{
		cin >> k[i];
		for(long long j = 0;j < k[i];j++)
		{
			cin >> a[i][j];
			cin >> t[i][j];
		}
	}
	for(long long i = 0;i < q;i++)
	{
		cin >> start;
		cin >> ending;
		ans += moved(start,ending,-1); 
	}
	return 0;	
} 
