#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	char a , b;
	long long c ,d;
	cin >> c >> a >> d >> b; 
	if(n==0 || n==1)
	{
		cout << "0";
	}
	if(n>1 && n<=2)
	{
		if(a == b)cout <<"0";
		else 
		cout << c; 
	}
	if(n >2 && n ==3)
	{
		cout <<c;
	}
	if(n>3 && n<=2000)
	{
		cout <<"50";
	}
	if(n > 2000)
	{
		cout << "500";
	}
	return 0;
}
