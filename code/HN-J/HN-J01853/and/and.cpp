#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("andin","r",stdin);	
	freopen("andout","w",stdout);
	int n,m,b=0;
	cin >> n >> m;
	int a[200001];
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i] < a[i+1])
		{
			b = a[i+1];
			a[i+1] = a[i];
			a[i] = b;
		}
		for(int j=1;j<=n;j++)
		{
			if(a[j] < a[j+1])
			{
				b = a[j+1];
				a[j+1] = a[j];
				a[j] = b;
			}	
		}	
	}
	cout << a[1];
	return 0;
} 
