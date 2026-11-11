#include <bits/stdc++.h>
using namespace std;
string a, x, b,y;
int main (){
    freopen("travel.in", "r" , stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> x >> b >> y;
    if(a == b && a != 1 && a!= 16){
        if(x[1] == y[1] && x[0] == y[0]){
            if((x[2] <=  'C' && y[2] <=  'C') || (x[2] >= 'D' && y[2] >= 'D')){
                if(int(x[2]) - int(y[2]) == -1 || int(x[2]) - int(y[2]) == 1){
                    cout << 1111;
                }
                else cout << 1110;
            }
            else cout << 1100;
        }
        else cout << 1000;
    }
    else cout << "0000";
    return 0;
}
