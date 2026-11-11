#include<bits/stdc++.h>
using namespace std;

struct node
{
	char w;
	long long num;
}m[200005];
int n;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		char a;
		long long b;
		cin >> b >> a;
		m[i].w = a;
		m[i].num = b;
	}
	long long l = 1,r = n,ans = 0;
	while(l < r)
	{
		if(m[l].w == m[r].w)
		{
			long long cut = min(m[l].num,m[r].num);
			m[l].num -= cut;
			m[r].num -= cut;
			if(m[l].num == 0)l++;
			else r--;
		}
		else
		{
			long long cut = min(m[l].num,m[r].num);
			m[l].num -= cut;
			m[r].num -= cut;
			if(m[l].num == 0)l++;
			else r--;
			ans += cut;
		}
	}
	cout << ans;
	return 0;
}
