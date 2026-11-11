#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string S1,S2,a,b;
    cin >> a >> S1 >> b >> S2;
    int y = (int)((a[0] - '0') * 10),e = (int)(a[1] - '0'),Y = (int)((b[0] - '0') * 10),E = (int)(b[1] - '0');
    int r = y + e,x = Y + E;
    if (r == x) {
        int f = (int)((S1[0] - '0')* 10),s = (int)(S1[1] - '0'),F = (int)((S2[0] - '0')* 10),S = (int)(S2[1] - '0');
        int xiaoR = f + s;
        int xiaoX = F + S;
        if (xiaoR == xiaoX){
            char t = S1[2],T = S2[2];
            if ((t == 'F' && T == 'D') ||(t == 'A' && T == 'B')||(t == 'A' && T == 'C')||(t == 'B' && T == 'C')){
                int xiaor = (int)(t - 'A'),xiaox = (int)(T - 'A');
                if (abs(xiaor - xiaox) == 1){
                    cout << 1 << 1 << 1 << 1;
                    return 0;
                }else{
                    cout << 1 << 1 << 1 << 0;
                    return 0;
                }
            }else {
                cout << 1 << 1 << 0 << 0;
                return 0;
            }
        }else{
            cout << 1 << 0 << 0 << 0;
            return 0;
        }
    }
    else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    return 0;
}
