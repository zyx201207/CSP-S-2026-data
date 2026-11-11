#include<iostream>
using namespace std;
int n,m,a[1001],c=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i]==a[j])
			{
				a[i]++;
				c++;
			}
		}
	}
	cout << c;
	return 0;
}
