// GZ-J00002 утсю╨Г 
#include <bits/stdc++.h>
using namespace std;
int n,a1,sum,g1;
string a,s,a2,a3,a4;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n ==1)
	{
		cout << 0;
	}
	for(int i = 0;i<n;i++)
	{
		cin >>a1 >>s;
		for(int j = 0 ;j<a1;j++)
		{
			a3 = a2;
			a2 += s;
			a4 = a3+a2;
		}
	}
	int g = a2.length();
	if(g%2==1)
	{
		g1 = g-1;
	}
	else g1 = g;
	for(int i=0;i<g1/2;i++)
	{
		if(a2[i] != a2[g+1-i])
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}
