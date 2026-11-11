#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt = 0;
	int t[n+1];
	string C2;
	char C1;
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> C1;
		C2 += a*C1;
		t[i] = a;
	}
	for(int j = 1;j <= n+1;j++)
	{
		if(t[j]%2 == 0 && t[j+t[j]] != C2[j-1])
		{
			cnt += t[j] / 2;
		}
	}
	cout << cnt;
	return 0;
}
