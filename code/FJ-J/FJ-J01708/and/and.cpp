#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

const int MAXN = 2e5+5;
int a[MAXN] = {0};
bool f[MAXN] = {0};

ll read()
{
	ll res = 0;
	bool f = 0;
	char tc = getchar();
	while(tc < '0' || tc > '9')
	{
		if(tc == '-') f = 1;
		tc = getchar();
	}
	while(tc >= '0' && tc <= '9')
	{
		res = (res<<1)+(res<<3)+(tc^48);
		tc = getchar();
	}
	return f?-res:res;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n = read(),m = read();
	for(int i = 0;i < n;i++) a[i] = read();
	
	int ans = 0;
	for(int i = 30;i >= 0;i--)
	{
		int base = 1<<i,cnt = 0;
		for(int j = 0;j < n;j++)
			if((a[j]&base) && !f[j]) cnt++;
		if(cnt < m) continue;
		
		ans += base;
		for(int j = 0;j < n;j++)
			if(!(a[j]&base)) f[j] = 1;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
3 15 12 12
*/
