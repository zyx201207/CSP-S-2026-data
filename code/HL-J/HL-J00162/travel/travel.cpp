#include<bits/stdc++.h>
using namespace std;
struct b{
    int x;
    string y;
}b[5];

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a[5];
    cin >> a[1] >> b[1].x >> b[1].y;
    cin >> a[2] >> b[2].x >> b[2].y;
    if(a[1] == a[2]){
        cout << "1";
    }
    else{
        cout << "0000";
        return 0;
    }
    if(b[1].x == b[2].x){
        cout << "1";
    }
    else{
        cout << "000";
        return 0;
    }
    if(b[1].y == "A" || b[1].y == "B" || b[1].y == "C" && b[2].y == "A" || b[2].y == "B" || b[2].y == "C"){
        cout << "1";
    }
    else if(b[1].y == "D" || b[1].y == "F" && b[2].y == "D" || b[2].y == "F"){
        cout << "1";
    }
    else{
        cout << "00";
        return 0;
    }

    if(b[1].y == "A"){
        if(b[2].y == "B"){
            cout << "1";
        }
        else{
            cout << "0";
            return 0;
        }
    }
    if(b[1].y == "B"){
        if(b[2].y == "A" || b[2].y == "C"){
            cout << "1";
        }
        else{
            cout << "0";
            return 0;
        }
    }
    if(b[1].y == "C"){
        if(b[2].y == "B"){
            cout << "1";
        }
        else{
            cout << "0";
            return 0;
        }
    }
    if(b[1].y == "D"){
        if(b[2].y == "F"){
            cout << "1";
        }
        else{
            cout << "0";
            return 0;
        }
    }
    return 0;
}
