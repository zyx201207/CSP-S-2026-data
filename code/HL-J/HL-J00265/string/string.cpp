#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct node
{
	int a;
	char c;
}str[N] = {};
signed main()
{
	int n;
	cin >> n;
	int k = 0;
	for(int i = 1; i <= n; ++i)
	{
		cin >> str[i].a >> str[i].c;
		k += str[i].a;
	}
	int cnt = 0;
	for(int i = 1, j = k; i <= (k / 2) && j >= (k / 2);)
	{
		if(str[i].a != 0 && str[j].a != 0)
		{
			if(str[i].c != str[j].c)
			{
				cnt += abs(str[i].a - str[j].a);
				str[i].a -= max(str[i].a, str[j].a);
				str[j].a -= max(str[i].a, str[j].a);
				continue;
			}
			else if(str[i].c == str[j].c)
			{
				str[i].a -= max(str[i].a, str[j].a);
				str[j].a -= max(str[i].a, str[j].a);
				continue;
			}
		}
		else if(str[i].a == 0 && str[j].a != 0)  ++i;
		else if(str[i].a != 0 && str[j].a == 0)  --j;
		else if(str[i].a == 0 && str[j].a == 0)  ++i, --j;
	}
	cout << cnt;
	return 0;
}
