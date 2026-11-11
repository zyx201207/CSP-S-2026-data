#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s=" ";
struct zifuchuan
{
	long long a;
	char c;
}z[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> z[i].a >> z[i].c;
		for(int j=1;j<=z[i].a;j++)
		{
			s += z[i].c;
		}
	}
	int ans = s.size()-1;
	for(int i=1;i<=ans/2;i++)
	{
		if(s[i] != s[ans+1-i])
		{
			s[ans+1-i] = s[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
