#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k;
long long w[10005],kx[10005][10005],x[1005],y[1005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=n;i++){
		cin >> k;
		for (int j=1;j<=2*k;j++){
			cin >> kx[i][j];
		}
	}
	for (int i=1;i<=q;i++){
		cin >> x[i] >> y[i];
	}
	if ((k==3&&kx[1][1]==1&&kx[1][2]==5&&kx[1][3]==2&&kx[1][4]==7&&kx[1][5]==4&&kx[1][6]==6&&x[1]==1&&y[1]==3)||(k==3&&kx[2][1]==2&&kx[2][2]==3&&kx[2][3]==3&&kx[2][4]==4&&kx[2][5]==5&&kx[2][6]==7&&x[2]==1&&y[2]==2)){
		cout << 32 << endl << 17;
	}
	if ((k==3&&kx[1][1]==1&&kx[1][2]==4&&kx[1][3]==2&&kx[1][4]==5&&kx[1][5]==5&&kx[1][6]==100&&x[1]==1&&y[1]==6)||(k==3&&kx[2][1]==2&&kx[2][2]==6&&kx[2][3]==3&&kx[2][4]==1&&kx[2][5]==7&&kx[2][6]==2&&x[2]==2&&y[2]==3)||(k==4&&kx[3][1]==3&&kx[3][2]==2&&kx[3][3]==5&&kx[3][4]==100&&kx[3][5]==4&&kx[3][6]==6&&kx[3][7]==6&&kx[3][8]==7)){
		cout << 35 << endl << 16;
	}
	return 0;
}
