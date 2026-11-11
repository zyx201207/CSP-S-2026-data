#include <iostream>
#include <string>
#include <map>
using namespace std;

long long a[200005];
char c[200005];
map <long long,char> mp;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,cur = 0,cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) mp[++cur] = c[i];
	}
	for (int i = 1; i <= cur / 2; i++)
	{
		if (mp[i] != mp[cur - i + 1]) cnt++;	
	}
	cout << cnt;
	return 0;
 } 
