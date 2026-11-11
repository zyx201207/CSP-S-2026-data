#include <bits/stdc++.h>
using namespace std;
int c,t,s[2];
long long num1,num2;
int ans=0;
int main()
{
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    cin >> c>>t;
    cin >>num1;
    for (int i=1;i<=1;i++)
    {
		cin >>num2;
		s[i]=num2-num1;
		swap(num1,num2);
	}
	int as=t/s[1];
	for (int i=1;i<=c;i++)
	{
		for (int j=i+2*as-1;j<=c;j++)
		{
			ans++;
		}
	}
	cout <<ans;
    return 0;
}
