#include <iostream>
using namespace std;
int n,a[200005];
long long ans;
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
	int l = 1,r = n,l1 = 0,r1 = 0;
	while(l < r)
	{
		int k = min(a[l] - l1,a[r] - r1);
		if(c[l] != c[r]) ans += k;
		l1 += k;r1 += k;
		if(l1 == a[l]) l++,l1 = 0;
		if(r1 == a[r]) r--,r1 = 0;
	}
	cout << ans << endl;
	return 0;
}
