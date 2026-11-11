#include <iostream>
using namespace std;
int n,m,ans,a[200005];
bool check(int x)
{
	int cnt = 0;
	for(int i = 1;i <= n;i++) if((a[i] & x) == x) cnt++;
	return cnt >= m;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 30;i >= 0;i--)
	{
		int k = (1 << i);
		if(check(ans | k)) ans |= k;
	}
	cout << ans << endl;
	return 0;
}
