#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	string c,b;
	int n, m,maxn = 0,maxm = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] > maxn)
		{
			maxm = maxn;
			maxn = a[i];
		}
		else if(a[i] > maxm)
		{
			maxm = a[i];
		}
	}
	cout << maxm;
	int v = 2,i = 1;
	while(maxn > 0)
	{
		c[i] = maxn % v + 48;
		v = v*2;
		i++;
	}
	int cnt1 = c.size(),cnt = 0;
	i = 1, v = 2;
	while(maxm > 0)
	{
		b[i] = maxm % v + 48;
		v = v*2;
		i++; 
	}
	int cnt2 = b.size();
	v = 2;
	for(int i = 0;i < max(cnt1,cnt2)-1;i++)
	{
		int x = cnt1 - i,y = cnt2 - i;
		if(min(x,y) == 0)
		{
			min(x,y) == max(cnt1,cnt2)+1;	
		}	
		if(c[x] == b[y])
		{
			cnt += v;
		}
		v*=2;
	}
	cout << cnt;
	return 0;
}
