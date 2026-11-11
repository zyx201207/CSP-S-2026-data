#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,x;
long long a[500001];
long long a1[500001][500001],b1[500001][500001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1 ; i<=m ; i++){
		cin >> a[i];
	}
	for(int i=1 ; i<=n ; i++){
		cin >> x;
		for(int j=1 ; j<=x ; j++){
			cin >> b1[i][j] >> a1[i][j];
		}
	}
	long long x1,x2,y1,y2;
	cin >> x1 >> x2 >> y1 >> y2 ;
	return 0;
} 
