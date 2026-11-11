#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e6+5;
int c, t, n;
ll x[N], d;
int ly[N], ry[N], l1[N], r1[N], rz[N], lz[N];
ll sl1[N], sr1[N], sr[N], ans;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while(t--)
	{
		ans = 0;
		scanf("%d%lld", &n, &d);
		for(int i = 0; i <= n+1; i++)
			ly[i] = ry[i] = rz[i] = lz[i] = sl1[i] = sr1[i] = sr[i] = 0, l1[i] = r1[i] = 0;
		for(int i = 1; i <= n; i++)
			scanf("%lld", &x[i]);
		for(int i = 1, j = 1; i <= n; i++)
		{
			while(j < n && x[j+1]-x[i] <= d) j++;
			ry[i] = j, lz[j] = i;
		}
		for(int i = n, j = n; i >= 1; i--)
		{
			while(j > 1 && x[i]-x[j-1] <= d) j--;
			ly[i] = j, rz[j] = i;
		}
		for(int i = 1; i <= n; i++)
		{
			if(ry[ly[i]] == i && ly[i] != i) l1[i] = l1[ly[i]]+1;
			sl1[i] = sl1[i-1]+l1[i];
		}
		for(int i = n; i >= 1; i--)
		{
			if(ly[ry[i]] == i && ry[i] != i) r1[i] = r1[ry[i]]+1;
			sr1[i] = sr1[i+1]+r1[i];
		}
//		for(int i = n-1; i >= 1; i--)
//		{
//			if(!rz[i]) continue;
//			sr[i] = sr1[rz[i]]-sr1[ry[i]+1];
//			if(rz[i] == i+1) sr[i] -= r1[rz[i]];
//		}
		for(int i = 1; i <= n; i++)
		{
			if(ry[i]-1 <= i) continue;
			int j = ry[i]-1;
			if(!rz[j]) continue;
			ans += ry[j]-rz[j]+1;
			if(rz[j] == j+1) ans--;
			if(ly[ry[ry[i]]] == j) ans += r1[ry[ry[i]]];
			if(ly[j] == i) ans += l1[i];
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
