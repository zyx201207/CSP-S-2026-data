#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000005];
string s="0";
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		string xs;
		cin >> xs;
		for(int j=1;j<=a[i];j++)
		{
			s+=xs;
		}
	}
	int l=(s.length()-1)/2;
	for(int i=1;i<=l;i++)
	{
		if(s[i]!=s[s.length()-i])
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
