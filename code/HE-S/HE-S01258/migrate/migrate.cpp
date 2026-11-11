#include<iostream>
using namespace std;
int c,t,z=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=0;i<t;i++)
	{
		int n,d,x[1001];
		cin >> n >> d;
		for(int i=0;i<n;i++)
		{
			cin >> x[i];
			if(x[i]==x[i-1])
			{
				z++;
			}
		}
	}
	cout << z;
	return 0;
}
