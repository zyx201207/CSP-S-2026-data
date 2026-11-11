#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<vector>
using namespace std;
const int MAXN = 1e6 + 5;
long long c , t , n , d;
long long x[MAXN] , ans;
vector<int> vec[MAXN];
int count2(int x , int step , int v)
{
	if(x > v || vec[x].empty()) return -1;
	if(x == v) return step;
	for(int i = 0;i < vec[x].size();i++) return count2(vec[x][i] , step + 1 , v);
}
int countshortest(int u , int v)
{
	long long temp = x[v] - x[u] , cnt = 0;
	long long minn = (temp / d) + ((temp % d == 0) ? 0 : 1);
	for(int i = 0;i < vec[u].size();i++) if(count2(vec[u][i] , 1 , v) == minn) cnt++;
	return cnt;
}
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	scanf("%lld%lld" , &c , &t);
	while(t--)
	{
		ans = 0;
		scanf("%lld%lld" , &n , &d);
		for(int i = 1;i <= n;i++) scanf("%lld" , &x[i]);
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if((x[j] - x[i]) > d) break;
				vec[i].push_back(j);
			}
		}
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				if((j - i) < 3) continue;
				if(countshortest(i , j) == 2) ans++;
			}
		}
		printf("%lld\n" , ans);
	}
	return 0;
}
