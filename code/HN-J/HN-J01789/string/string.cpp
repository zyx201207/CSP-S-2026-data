#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	string S,c;
	long long n,ans = 0;
	int a;
	cin >> a;
	for(int i = 1;i <= a;i++)
	{
		cin >> n >> c;
		for(int i = 1;i <= n;i++)
		{
			S = S+c;
		}
	}
	int m = S.size();
	for(int i = 0;i < m / 2;i++)
	{
		if(S.substr(i,1) != S.substr(m-i-1,1));
		{
			ans += 1;
		}
	}
	cout << ans << endl;
	return 0;
}
