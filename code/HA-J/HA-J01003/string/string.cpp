#include <bits/stdc++.h>
using namespace std;
int n;
char s[6000000];
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n;
	int num;
	char s_;
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		cin >> num;
		cin >> s_;
		for (int j=ans; j<=ans+num; j++)
		{
			s[j]=s_;
			ans++;
		}
		
	}
	for (int i=1; i<=sizeof(s)+1; i++)
	{
		cout << s[i];
	}
	return 0;
}
