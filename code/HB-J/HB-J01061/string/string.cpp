#include<iostream>
using namespace std;
int main()
{
	freopen("r""string.in");
	freopen("w""string.out");
	
	int n,c=0;
	cin>>n;
	char a[n][2];
	for(int i=0;i<n;i++)
	{
		cin>>a[n][2];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[n+1][2];
		if(a[n][2]==a[n+1][2])
		c++;
		else
			if(a[n][2]==a[1][2])
			{
				cout<<c;
			}
	}
	return 0;
}
