#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a , b , s[5];
	cin >> a >> b;
    for(int i = 1;i <= 5;i++)
	{
		cin >> s[5];
	}
	if(a+b>7)
	{
		cout << a+b-1;
	}
	else
	{
		cout << (a+b)*2;
	} 
	return 0;
}
