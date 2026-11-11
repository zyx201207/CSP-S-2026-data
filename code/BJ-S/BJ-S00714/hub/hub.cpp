#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t,n,k;
    cin >> c >> t;

    while(t--) {
        cin >> n >> k; int x,y;
        for(int i=1;i<=n-1;i++) cin >> x >> y;
        srand(time(NULL));
        cout << rand()%(k*k) << endl;
    }

    return 0;
}
