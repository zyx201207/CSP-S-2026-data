#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 2e6 + 10;
int c,t;
ll a[N],b[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		int n;
		ll d;
		bool sub1 = true;
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
			b[i] = a[i] - a[i - 1];
			if(i >= 3 && b[i] != b[i - 1])
				sub1 = false;
		}
		if(sub1)
		{
			if(d <= b[2])
			{
				cout << "0\n";
				continue;
			}
			int l = (d + b[2] - 1) / b[2],r = 1 + l + l - 1;
//			cout << l << ' ' << r << '\n';
			if(r <= n && r > 0)
				cout << n - r + 1 << '\n';
			else
				cout << "0\n";
		}
	}
	return 0;
}
