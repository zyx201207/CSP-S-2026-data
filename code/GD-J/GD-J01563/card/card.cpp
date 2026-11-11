#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+2];
	for(int i =0;i<n;i++)
	{
		cin >> a[i];
	}
	if(a[0]==a[n-1])
	{
	 	cout << n << " " << 0;
	}
	else
	{
		cout << n << " " << n;
	}
	return 0;
}
