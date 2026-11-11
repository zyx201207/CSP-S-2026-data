#include <bits/stdc++.h>
using namespace std;
long long n,x;
long long num;
char y,a[10000000000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i =1;i<=n;i++)
	{
		cin >> x >> y;
		for (int i = num+1;i <= num + x;i++)
		{
			a[i] = y;
		}
		num+=x;
	}
	//cout << num;
	long long n = (num/2);
	for (int i = 1;i <= (num/2);i++)
	{
		if(a[i-1] == a[-i])
		{
			n--;
		}
	}
	//cout << n;
}
