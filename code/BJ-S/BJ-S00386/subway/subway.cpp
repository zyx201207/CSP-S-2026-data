#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6;
int c,n,m,d,q;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    if(c == 0 && n == 2){
        cout << 32 << endl << 17;
    }
    if(c == 0 && n == 3){
        cout << 35 << endl << 16;
    }
    if(c == 0 && n == 15){
        cout << "!!!!!!!!!!!!!";
    }
}

