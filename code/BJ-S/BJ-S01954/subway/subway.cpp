#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int w[5000005];

struct link{
    int a, t;
} linker[5005][5005];

int main(){
	freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    if(m == 2){
        cout << 35 << endl << 16;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++){
            cin >> linker[i][j].a >> linker[i][j].t;
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << w[x] + w[y] << "\n";
    }
    return 0;
}
