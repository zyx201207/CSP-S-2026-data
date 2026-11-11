#include<bits/stdc++.h>
using namespace std;

long long n, a[200005], b[200005];
long long s, p1 = 1, p2, q = 1, r1, l2, ans;
char c[200005];

int main()
{	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{	
		cin >> a[i] >> c[i];
		
		b[i] = b[i - 1] + a[i];
		s += a[i];
	}
	
	p2 = n;
	
	while(p1 <= p2)
	{
		r1 = b[p1];
		
		l2 = b[p2 - 1] + 1;
		
		long long t = min(r1, s - l2 + 1) - q + 1;
		
		if(c[p1] != c[p2])
		{
			ans += t;
		}
		
		q += t;
		
		if(q > r1) p1++;
		if(s - q + 1 < l2) p2--;
	}
	
	cout << ans << endl;
	
	return 0;
}
