#include<iostream>
using namespace std;

const int maxn = 1e4 + 50;
int c, n, m, d, q;
int w[maxn];
long long a[maxn][maxn], t[maxn][maxn], x[maxn], y[maxn];

int main(){

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> d >> q;

    for(int i = 1;i <= m;i ++) {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++){
        int k,f=1,l = 1;
        cin >> k;
        for(int j = 1;j <= k*2; j ++){
            if(j % 2 == 1){
                cin >> a[l][f];
            }else if(j % 2 == 0){
                cin >> t[l][f];
                f++;
                l++;
            }
        }
    }
    for(int i = 1;i <= q;i ++){
        cin >> x[i] >> y[i];
    }
    cout << w[1] + t[1][1] + t[1][2] +w[2];
    return 0;
}//subway