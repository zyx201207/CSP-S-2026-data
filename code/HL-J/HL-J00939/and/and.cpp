#include <bits/stdc++.h>
using namespace std;

string TentoR(int x,int R)
{
	string ans;
	while(x!=0)
	{
		int t = x % R;
		x /= R;
		if(t>=10) ans = char(t+55) + ans;
		else ans = to_string(t) + ans;
	}
	return ans;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
	int num = 0;
	int a[num];
    int max_num = 0;
    for(int i = 1;i<=n;i++)
    {
		if(1 <= m <= n <= 2 * pow (10,5) && 0 <= a[i] < pow(2,30))
		{
			max_num ++;
		}
	}
    cout << max_num;
    return 0;
}