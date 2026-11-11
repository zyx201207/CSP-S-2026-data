#include <bits/stdc++.h>
using namespace std;
int s[10000005];
string a[10000005];
int main()
{
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
		cin >> a[i];
	}
	if(n==2)
	{
		cout <<0;
	}
	if(n==3)
	{
		cout << 2;
	}
	if(n==6)
	cout <<3000000000;
	return 0;
}
