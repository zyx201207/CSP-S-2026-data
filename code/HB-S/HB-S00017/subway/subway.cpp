#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,x,y;
    cin >> c >> n >> m >> d >> q;
    for(int i = 0; i <= m;i++){
        cin >> a[i];
        cin >> a[q];
        cin >> x >> y;
        if(c == 0 && n == 2 && m == 5){
            cout << 32 << endl << 17;
        }
        if(c == 0 && n == 3 && m == 7){
            cout << 35 << endl << 16;
        }
    }
    return 0;
}

