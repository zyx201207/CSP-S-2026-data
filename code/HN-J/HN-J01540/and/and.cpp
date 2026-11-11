#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a1,a2,a3,a4,ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0,ans5 = 0,ans6 = 0;
	cin >> n >> m;
	cin >> a1 >> a2 >> a3 >> a4;
	for(int i = 1;i <= n;i++)
	{
	    ans1 += min(a1,a2);
	    ans2 += min(a1,a3);
	    ans3 += min(a1,a4);
	    ans4 += min(a2,a3);
	    ans5 += min(a2,a4);
	    ans6 += min(a3,a4);
	}
	cout << ans1 or cout << ans2 or cout << ans3 or cout << ans4 or cout << ans5 or cout << ans6;
	return 0;
}
