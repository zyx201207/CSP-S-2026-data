#include<bits/stdc++.h>
using namespace std;
long long n , m , a[500005] , c[500005] , minn = 0x3f3f3f3f;
long long cnt  , maxn , flag , l , r;
//bool book[500005];
void pdleft(long long sum , long long x)
{
	//cout << 11111111111;
	if(l < 1)
	{
		while(sum < m)
		{
			r ++;
			sum += abs(a[x] - a[r]);
			cnt ++;
			//cout << 2222 << ' ';
		}
		flag = 1;
		//cout << 11111111111;
		return;
	}
	else return;
}
void pdright(long long sum , long long x)
{
	if(r > n)
	{
		while(sum < m)
		{
			l --;
			sum += abs(a[x] - a[l]);
			cnt ++;
		}
		flag = 1;
		return;
	}
	else return;
}
void dfs(long long x)
{
	
	long long sum = 0;
	l = x-1 , r = x+1;
	while(sum < m)
	{
		//printf("%lld %lld %lld %lld\n",l,r,cnt,sum);
		pdright(sum , x);
		pdleft(sum , x);
		
		if(flag == 1) 
		{
			//cout << 1111111111;
			return;
		}
		long long sum1 , sum2;
		for(int i = l ; i <= x ; i ++)
		{
			sum1 += c[i+1];
		}
		for(int i = x ; i <= r ; i ++)
		{
			sum2 += c[i];
		}
		//mabye same but dontwanttodo..
		if(sum1 > sum2)
		{
			r ++;
			sum += sum2;
			cnt ++;
		}
		else
		{
			l --;
			sum += sum1;
			cnt ++;
		}
	}
	//cout << l << ' ' << r;
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		c[i] = abs(a[i] - a[i-1]);
		if(i == 1) continue;
		minn = min(minn , c[i]);
	}
	//cout << minn << endl;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(c[i] == minn)
		{
			//cout << i << endl;
			cnt = 1 , flag = 0;
			//memset(book , 0 , sizeof(book));
			dfs(i);
			//cout << l << ' ' << r << endl;
			//cout << cnt << endl;
			maxn = max(maxn , cnt);
		}
	}
	cout << maxn;
	return 0;
}
