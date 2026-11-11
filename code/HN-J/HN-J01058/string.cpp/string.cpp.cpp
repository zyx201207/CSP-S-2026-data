#include <bits/stdc++.h>
using namespace std;
int main() 
{
    //freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,x,num=0,sum=0,h;
	string t,a="";
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
	    cin >> x >> t;
	    sum += x;
		for (int j = 1;j <= x;j++)
		{
			a += t;
		}
	}
	if (sum % 2 == 1)
	{
	    h = sum / 2 + 1;
	}
	else
	{
		h = sum / 2;
	}
	for (int i = 0;i < h;i++)
	{
		if (a[sum-num-1] != a[i])
		{
			num++;
		}
	}
	cout << num;
	return 0;
} 
