#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n,a[N];
char b[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld%s",&a[i],&b[i]);
	}
	int l = 1,r = n,sum = 0;
	while(l < r)
	{
		if(a[l] == a[r] && b[l] == b[r])
			l++,r--;
		else if(a[l] < a[r] && b[l] == b[r])
		{
			a[r] -= a[l];
			l++;
		}
		else if(a[r] < a[l] && b[l] == b[r])
		{
			a[l] -= a[r];
			r--;
		}
		else if(a[l] == a[r])
			sum += a[l],l++,r--;
		else if(a[l] < a[r])
		{
			a[r] -= a[l];
			sum += a[l];
			l++;
		}
		else
		{
			a[l] -= a[r];
			sum += a[r];
			r--;
		}
	}
	cout << sum << endl;
	return 0;
}

