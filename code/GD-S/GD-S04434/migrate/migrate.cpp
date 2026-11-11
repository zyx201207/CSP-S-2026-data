#include <bits/stdc++.h>
using namespace std;
int island[200004];
bool move(long long set,long long dist,long long tgt)
{
	bool two_ways = false;
	long long min_ways = INT_MAX;
	for(long long i = set + 1;(island[i] - island[set] <= dist && i < tgt);i++)
	{
		int temp = move_way(i,tgt);
		min_ways = min(temp,min_ways);
	}
	for(long long i = set + 1;(island[i] - island[set] <= dist && i < tgt);i++)
	{
		if(min_ways == move_way(i,tgt))
		{
			two_ways = !two_ways;
			if(two_ways == false)
			{
				return false;
			}
		}
	}
	return two_ways;
}
long long move_way(long long start,long long d,long long ending)
{
	if(start = ending)
	{
		return 1;
	}
	for(long long i = start + 1;(island[i] - island[start] <= d && i < ending);i++)
	{
		move_way(i,d,ending);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t
	cin >> c >> t;
	long long (round = 0;round < t;round++)
	{
		long long n,d;
		cin >> n >> d;
		for(long long i = 0;i < n;i++)
		{
			cin >> island[i];
		}
		long long pairs = 0;
		for(long long i = 0;i < n;i++)
		{
			for(long long j = 0;j < n;j++)
			{
				if(j != i)
				{
					pairs += move(i,d,j);
				}
			}
		}
	}
	return 0;	
} 
