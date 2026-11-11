#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
long long ans;
struct Node
{
	long long num;
	char x;
}a[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i].num >> a[i].x;
	int l = 1,r = n;
	while(l < r)
	{
		long long s = min(a[l].num,a[r].num);
		a[l].num -= s;
		a[r].num -= s;
		if(a[l].x != a[r].x) ans += s;
		if(a[l].num == 0) l++;
		if(a[r].num == 0) r--;
	}
	cout << ans;
    return 0;
}
