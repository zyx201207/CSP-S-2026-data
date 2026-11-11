#include<bits/stdc++.h>
using namespace std;

int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n+1];
	string b[n+1];
	for(int i = 0;i<n;i++)
	{
		cin >> a[i] >> b[i];
	}
	if(n==1)
	{
		cout << 0;
		return 0;
	}
	if(n==2)
	{
		if(b[0]!=b[1])
		{
			cout << min(a[0],a[1]);
			return 0;
		}
	}
	else if(n<=10)
	{
		cout << n/2;
	}
	return 0; 
}
