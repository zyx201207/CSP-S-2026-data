#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,a1,b1;
    cin >> a >> a1 >> b >> b1;
    if(a != b){
        cout << "0000";
        return 0;
    }
    else cout << "1";
    if(a1[0] != b1[0] || a1[1] != b1[1]){
        cout << "000";
        return 0;
    }
    else cout << "1";
    if(a1[2] == 'A' || a1[2] == 'B' || a1[2] == 'C'){
        if(b1[2] == 'D' || b1[2] == 'F'){
            cout << "00";
            return 0;
        }
        else cout << "1";
    }
    else{
        if(b1[2] == 'A' || b1[2] == 'B' || b1[2] == 'C'){
            cout << "00";
            return 0;
        }
        else cout << "1";
    }
    if(abs(a1[2] - b1[2]) == 1) cout << "1";
    else cout << "0";
    return 0;
}
