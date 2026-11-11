#include<bits/stdc++.h>
using namespace std;
struct arr
{
	long long num;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int l = 0;
	long long x;
	char cc;
	for(int i = 1;i<=n;i++)
	{
	    cin >> x;
	    cin >> cc;
	    a[i].num = x + a[i-1].num;
	    a[i].c = cc;
	    l += x;
	}
	
	int k1 = 1;
	int k2 = n;
	long long ans = 0;

	for(int i = 1;i<=l/2;i++)
	{
		if(i > a[k1].num)
		{
			k1++;
		}
		if(l-i+1 == a[k2-1].num)
		{
			k2--;
		}
		if(a[k1].c != a[k2].c)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
