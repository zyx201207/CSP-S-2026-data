#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long n , m , ans = -1;
long long crys[500005] , diff[500005];
void solve(long long l , long long r)
{
	if(l > r) return;
	long long mid = (r - l) / 2 + l;
	for(int i = 1;i <= n;i++) diff[i] = crys[mid] - crys[i];
	sort(diff + 1 , diff + n + 1);
	long long temp = 1 , sumn = 0 , temp2 = -1;
	while((sumn + diff[temp]) <= m && temp <= n)
	{
		if(diff[temp] < 0)
		{
			temp++;
			continue;
		}
		if(temp2 == -1 && diff[temp] >= 0) temp2 = temp;
		sumn += diff[temp];
		++temp;
	}
	ans = max(ans , temp - temp2);
	solve(l , mid - 1);
	solve(mid + 1 , r);
}
int main()
{
	freopen("crystal4.in" , "r" , stdin);
//	freopen("crystal.out" , "w" , stdout);
	scanf("%lld%lld" , &n , &m);
	for(int i = 1;i <= n;i++) scanf("%lld" , &crys[i]);
	sort(crys + 1 , crys + n + 1);
	bool flag = true;
	int d = crys[2] - crys[1];
	for(int i = 2;i <= n;i++)
	{
		if(crys[i] - crys[i - 1] != d)
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		cout << m / d;
		return 0;
	}
	solve(1 , n);
	printf("%lld" , ans);
	return 0;
}
