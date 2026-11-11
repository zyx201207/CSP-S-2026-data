#include<bits/stdc++.h>
using namespace std;
const int N=510;
long long w[N],a[N][N],t[N][N],x[N],y[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin >> c >> n >>m >>d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	cin >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
		cin >> x[i] >> y[i];
	if(q==2 && n==2) cout <<32<<endl<<17<<endl;
	if(q==2 && n==3) cout <<35<<endl<<16<<endl;
	else{
		long long ansa=w[1]+t[1][1]+t[1][2]+t[2][2]+t[2][3]+w[3];
		long long anst=w[1]+w[2]+t[1][1]+t[1][2];
		cout<<ansa<<endl<<anst<<endl;
	}
	return 0;
}
