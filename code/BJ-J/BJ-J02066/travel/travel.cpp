#include<bits/stdc++.h>
using namespace std;
string a1, b1, a2, b2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a1 >> b1 >> a2 >> b2;
    if(a1 == a2){
        cout << 1;
    }else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    if(b1[0] == b2[0] && b1[1] == b2[1]){
        cout << 1;
        if(('A' <= b1[2] && b1[2] <= 'C') && ('A' <= b2[2] && b2[2] <= 'C')){
            cout << 1;
            if(b1[2] == 'A' && b2[2] == 'B'){
                cout << 1;
            }else if(b1[2] == 'B'){
                cout << 1;
            }else if(b1[2] == 'C' && b2[2] == 'B'){
                cout << 1;
            }else{
                cout << 0;
            }
        }else if(('D' <= b1[2] && b1[2] <= 'F') && ('D' <= b2[2] && b2[2] <= 'F')){
            cout << 1;
            cout << 1;
        }else{
            cout << 0 << 0;
        }
    }else{
        cout << 0 << 0 << 0;
    }
    return 0;
}
