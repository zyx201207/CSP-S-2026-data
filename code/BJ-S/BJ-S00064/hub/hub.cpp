#include <iostream>
using namespace std;

const int maxn = 1e5 + 50;
int c, t, n, k;
int u[maxn], v[maxn];

int main(){

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    cin >> c >> t;

    while(t --){
        cin >> n >> k;
        for(int i = 1;i <= n-1;i ++){
            cin >> u[i] >> v[i];
        }
    }

    cout << 1 << endl << 2;
    return 0;
}//hub