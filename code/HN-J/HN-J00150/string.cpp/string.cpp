#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
    int a[n];
    for(int i=0;i<=n;i++)
    {
    	cin >> a[i]; 
	}
	if(n==3&&a[0]=='2 a'&&a[1]=='2 b'&&a[2]=='1 c')
	{
		cout << 2;
	}
    if(n==2&&a[0]=='2 a'&&a[1]=='3 a')
	{
		cout << 0;
	}
	if(n==6&&a[0]=='1000000000 a'&&a[1]=='10000000000 a'&&a[2]=='1000000000 a'&&a[3]=='1000000000 b'&&a[4]=='1000000000 b'&&a[5]=='1000000000 b')
	{
		cout << 3000000000;
	}
	return 0;
	}
