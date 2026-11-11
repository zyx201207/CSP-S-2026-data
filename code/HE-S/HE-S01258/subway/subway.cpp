#include<iostream>
using namespace std;
int c,n,m,d,q,a[1001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++)
	{
		cin >> a[i];
	}
	cout >> c*n;
	return 0;
}
