#include <bits/stdc++.h>
using namespace std;

string c1, c2, c3, c4, c2_1, c4_1;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> c2 >> c3 >>c4;
    for(int i=0; i<=1; i++){
        c2_1 += c2[i];
        c4_1 += c4[i];
    }
    if(c1==c3) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    if(c2_1==c4_1){
        cout << 1;
        if(c2[2]>='A' && c2[2]<='C'){
            if(c4[2]!=c2[2] && c4[2]>='A' && c4[2]<='C') cout << 1;
            else cout << 0;
        }
        else if(c2[2]>='D' && c2[2]<='E'){
            if(c4[2]!=c2[2] && c4[2]>='D' && c4[2]<='E') cout << 1;
            else cout << 0;
        }
    }
    else cout << 00;
    if(c2[2]==c4[2]-1 || c2[2]==c4[2]+1) cout << 1;
    else cout << 0;
    return 0;
}
