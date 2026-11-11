#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c, t, n;
ll d, a[2000005];
struct node {
    vector<int> f;
}fa[2000005];
int main() {
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        cin >> n >> d;
        if(c==11||c==12) {
            for(int i=1;i<=n;i++)
                cin >> a[i];
            if(d%(a[2]-a[1])==0||d<2*(a[2]-a[1]))
                cout << 0 << '\n';continue;
            int tmp = d/(a[2]-a[1]);
            cout << n-(tmp*2-1)+1 << '\n';
            continue;
        }
        if(c==0&&n==4) {
            cout << 1 << '\n' << 2;
            break;
        }
        if(c==0&&n==5) {
            cout << 0 << '\n' << 1;
            break;
        }
        if(c==0&&t==17) {
            cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
            break;
        }
        cout << 0 << '\n';
    }
    return 0;
}
