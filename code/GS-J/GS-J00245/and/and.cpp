#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;
ll z[N];

bool cmp(int x , int y)
{
	return x > y;
}

int main()
{
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	ll a , b;
	scanf("%lld%lld" , &a , &b);
	for(ll i = 1 ; i <= a ; ++ i)
	{
		scanf("%lld" , &z[i]);
	}
	
	sort(z + 1 , z + 1 + a , cmp);
	
	ll ans = z[1] & z[2];
	
	for(int i = 3 ; i <= b ; ++ i)
	{
		ans &= z[i];
	}
	
	printf("%lld" , ans);
	
	return 0;
}
