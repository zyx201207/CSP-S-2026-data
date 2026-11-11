#include<bits/stdc++.h>
using namespace std;
int zh(string x){
    int ans = 0;
    for(int i = 0; i < x.size(); i++){
        ans = ans * 10 + (int)(x[i] - '0');
    }
    return ans;
}
int zh2(string x){
    int ans = 0;
    for(int i = 0; i < x.size() - 1; i++){
        ans = ans * 10 + (int)(x[i] - '0');
    }
    return ans;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a1 = zh(c1), a2 = zh(c2);
    int b1 = zh2(s1), b2 = zh2(s2);
    char zw1 = s1[2], zw2 = s2[2];
    //cout << a1 << a2 << b1 << b2 << zw1 << zw2;
    if(a1 == a2){
        cout << "1";
        if(b1 == b2){
            cout << "1";
            if((zw1 == 'A' ) && (zw2 == 'B') || (zw1 == 'B' && (zw2 == 'C' || zw2 == 'A')) || (zw1 == 'C' && zw2 == 'B')){
                cout << "11";
            }else if(zw1 == 'A' && zw2 == 'C' || zw2 == 'A' && zw1 == 'C'){
                cout << "10";
            }else if(zw1 == 'D' && zw2 == 'F' || zw2 == 'D' && zw1 == 'F' ){
                cout << "11";
            }else{
                cout << "00";
            }
        }else cout << "000";
    }else{
        cout << "0000";
    }
}
