#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	string a,b;
	int n,sum;
	long long ans =0;
	int x;
	cin >> n;
	for (int i = 1;i<= n;i++) 
	{
		cin >> x >> b ;
		for (int i = 1;i<= x;i++)
		{
			a +=b;
		}
		sum+=x;
	}
	sum/=2;
	for (int i = 0;i<sum;i++)
	{
		if(a[i] != a[n-i+1])
			ans++;
	}
	cout << ans;
}

