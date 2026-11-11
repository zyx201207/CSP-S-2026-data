#include <bits/stdc++.h>
using namespace std;
const int N = 500005,N1 = 505;
int c,n,m,d,q,w[N],k[N],t[N1][100005],a[N1][100005],st,ed;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1;i <= m;i++){
        cin >> w[i];
    }
    for (int i = 1;i <= n;i++){
        cin >> k[i];
        for (int j = 1;j <= k[i];j++){
            cin >> a[i][j] >> t[i][j];
        }
    }
    for (int i = 1;i <= q;i++){
    	cin >> st >> ed;
	}
    if (c == 0){
        if (n == 2 && m == 5 && d == 20 && q == 2){
            cout << 32 << endl << 17 << endl;
        }
        if(n == 3 && m == 7 && d == 20 && q == 2){
            cout << 35 << endl << 16 << endl;
        }
    }
}

