#include <iostream>
using namespace std;
int n,m,a;
int b[10005],c[10005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x = -1;
	int d = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a;
		if(a > x)
		{
			b[i] = a;
			x = a;
		}
	}
	for(int j = 1;j <= n;j++)
	{
		c[j] = b[j] and b[j+1];
		d = max(c[j],c[j+1]);
	}
		
		cout << d;
	return 0;
}
