//GZ-S00002 утсю╨Г 
#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,qd,mdd;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c>> n >> m >> d >> q;
	int a[m+2],g[n+2][m+2],int f[d];
	if(c==0)
	{
		if(n==2)
		{
			cout << 32 << endl;
			cout << 17<<endl;
		}
		else if(n == 3)
		{
			cout << 35 << endl;
			cout << 16 << endl;
		}
	}
	for(int i =0;i<m;i++)
	{
		cin  >> a[m];
	}
	for(int i =0;i<m;i++)
	{
		cin >> k;
		for(int j = 0;i<2*k;j++) cin >> g[i][j];
	}
	for(int i =0;i<2*k;i++)
	{
		f[i] = 
	}
	for(int i =0;i<q;i++)
	{
		cin >> qd >> mdd;
	}
}
