#include <iostream>
using namespace std;

#define ll long long

const int N = 1e6 + 1;
int edges[N][2];

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n - 1; ++i) cin >> edges[i][0] >> edges[i][1];
    }
    
    return 0;
}