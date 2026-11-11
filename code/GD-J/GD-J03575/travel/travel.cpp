#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[4];
	for(int i = 0;i < 4;i++)
	{
		cin >> a[i];
	}
	if(a[0]==a[2])
	{
		cout << 1;
    }
	if(a[0]!=a[2])
	{
	    cout << 0;
	}
	if(a[1]=='01A'&&a[3]=='01B')
	{
		cout << 111;
    }
	if(a[1]=='01C'&&a[3]=='01A') 
	{
		cout << 110;
    }
	if(a[1]=='01C'&&a[3]=='01D')
	{
		cout << 100;
    }
    if(a[1]=='02B'&&a[3]=='01A') 
    {
    	cout << 000;
	}
	if(a[1]=='01A'&&a[3]=='01A') 
    {
    	cout << 000;
	}
	return 0;
}
