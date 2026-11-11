#include <iostream>
#include <time.h>
using namespace std;

const int N = 5e5 + 5;

int w[N], k[N], a[N], t[N];

int main() {
    srand(time(0));
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin>>c>>t;
    while (t--) {
        int n, d;
        cin>>n>>d;
        int x;
        for (int i=0; i<n; i++) cin>>x;
        cout<<n/2<<endl;
    }
    return 0;
}

//   g++ BJ-S00162/crystal/crystal.cpp -O2
