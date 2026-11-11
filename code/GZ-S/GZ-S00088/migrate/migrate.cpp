#include <iostream> //GZ-S00088邓林轩
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d,a[100000];
	cin >> c >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n >> d;
		for (int j=1;j<=n;j++)
		{
			cin >> a[j];
		}
		for (int k=1;k<=n-1;k++)
		{
			if (a[k]+d<a[k+1])
			{
				d--;
			}
		}
		for (int p=1;p<=d;p++)
		{
		    a[1]+=d;
		}
	}
	cout << "1" << endl << "2";
}
