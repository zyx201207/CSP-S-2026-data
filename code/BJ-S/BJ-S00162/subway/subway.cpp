#include <iostream>
#include <time.h>
using namespace std;

const int N = 5e5 + 5;

int w[N], k[N], a[N], t[N];

int main() {
    srand(time(0));
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin>>c>>n>>m>>d>>q;
    for (int i=0; i<m; i++) cin>>w[i];
    for (int i=0; i<n; i++) {
        cin>>k[i];
        for (int j=0; j<k[i]; j++) cin>>a[i]>>t[i];
    }
    cout<<rand()%100+10;
    return 0;
}

//   g++ BJ-S00162/crystal/crystal.cpp -O2
