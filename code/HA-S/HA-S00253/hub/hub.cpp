#include <bits/stdc++.h>;
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for(int m=1;m<=n;m++)
		{
			if(a[m]>a[m+1])
			{
				a[i]==a[i+1];
				a[i+1]==a[i];
			}
		}
	}
	for(int i =1;i<=n;i++)
	{
		cout<<a[i];
	}
	return 0;
}
