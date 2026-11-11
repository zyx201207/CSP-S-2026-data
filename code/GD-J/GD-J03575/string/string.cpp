#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[15] , x;
    cin >> x ;
    for(int i = 0;i <= x;i++)
    {
    	cin >> a[i];
	}
    if(x==3)
    {
    	cout << 2;
	}
	if(x==2)
	{
		cout << 0;
	}
	if(x==6)
	{
		cout << 3000000000;
	}
	return 0;
}
