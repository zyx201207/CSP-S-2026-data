#include <bits/stdc++.h>
using namespace std;
int n,x,sum,cnt;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		cin >> x >> c;
		sum += x;
		while(x--) s += c;
	}
	for(int i = (sum + 1) / 2;i < sum;i++)
	{
		if(s[i] != s[sum - i - 1]) cnt++;
	}
	cout << cnt;
	return 0;
}

