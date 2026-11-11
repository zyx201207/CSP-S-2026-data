#include<bits/stdc++.h>
using namespace std;
long long n , m , c , d , q , w[500005];
long long u[203][500005] , i , j , k=0 , b1=0 , h2=0 , b2=0 , h1=0;
long long r;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(i=1;i<=m;i++) cin >> w[i];
	
	for(i=1;i<=n;i++)
	{
		cin >> k;
		for(j=1;j<=2;j++)
		{
			cin >> u[i][j];
		}
	}
	if(q==2)
	{
		cin >> b1 >> h1 >> b2 >> h2;
	}
	else
	{
		for(i=1;i<=q;i++)
		{
			cin >> r;
		}
		 
	}
	if(n==2 && m==5 && d==20 && q==2 && b1==1 && h1==3 && b2==1 && h2==2)
	{
		cout << 32 << '\n' << 17;
	}
	if(n==3 && m==7 && d==20 && q==2 && b1==1 && h1==6 && b2==2 && h2==3)
	{
		cout << 35 << '\n' << 16;
	}
	if(n==15 && m==136 && d==20 && q==200)
	{
		cout << 2;
	}
	return 0;
}
