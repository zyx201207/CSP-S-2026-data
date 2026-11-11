#include<bits/stdc++.h>
using namespace std;

struct S
{
	int s;
	string h;
}a[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt = 0;
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i].s >> a[i].h;
	int l = 1,r = n;
	while(l < r)
	{
		if(a[l].s < a[r].s)
		{
			if(a[l].h != a[r].h) cnt += a[l].s; 
			a[r].s -= a[l].s;
			l++;
		}
		else if(a[l].s == a[r].s)
		{
			if(a[l].h != a[r].h) cnt += a[l].s; 
			r--;
			l++;
		}
		else
		{
			if(a[l].h != a[r].h) cnt += a[r].s; 
			a[l].s -= a[r].s;
			r--;
		}
	}
	cout << cnt;
	return 0;
}
