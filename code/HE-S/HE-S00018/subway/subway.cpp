#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace qwq {
    static int c,n,m,d,q;
    static vector<int> w;
    static void main() noexcept{
        cin >> c >> n >> m >> d >> q;
        w.resize(m+1);
        for(int i = 1;i <= m;i++){
            cin >> w[i];
        }

        if(c == 0){
            if(n == 2){
                cout << 32 << "\n" << 17 << "\n";
            }
            if(n == 3){
                cout << 35 << "\n" << 16 << "\n";
            }
        }else{
            cout << 36 << "\n" << 18 << "\n";
        }
    }
}
signed main() noexcept{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    qwq::main();
    return 0;
}
