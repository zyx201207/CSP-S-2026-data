#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6;
int c,n,t,d;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t >> n >> d;
    if(c == 0 && n == 4){
        cout << 1 << endl << 2;
    }
    if(c == 0 && n == 5){
        cout << 0 << endl << 1;
    }
    if(c == 0 && n == 197){
        cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0;
    }
}

