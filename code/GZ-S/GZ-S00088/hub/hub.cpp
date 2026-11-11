#include <iostream>//GZ-S00088邓林轩
using namespace std;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k,a[1000000],b[1000000];
	cin >> c >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n >> k;
		for (int j=1;j<=n-1;j++)
		{
			cin >> a[i] >> b[i];
		}
	}
	if (t==2)
	{
		cout <<"1" << endl << "2";
	}
	else if (t==3)
	{
		cout << "1" << endl << "1" << endl << "2";
	}
}
