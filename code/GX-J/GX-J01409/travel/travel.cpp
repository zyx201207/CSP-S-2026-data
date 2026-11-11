#include <bits/stdc++.h>
using namespace std;

int c1, c2, a1, a2, b1, b2;
string s1, s2;
int a[4];

int main(){

    freopen("travel.in", "r", stdin);
    freopen("travel.out", " w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] - '0' <= 9 && s1[i] - '0' >= 0){
            a1 = a1 * 10 + s1[i] - '0';
        }
        else{
            if(s1[i] == 'A'){
                b1 = 1;
            }
            else if(s1[i] == 'B'){
                b1 = 2;
            }
            else if(s1[i] == 'C'){
                b1 = 3;
            }
            else if(s1[i] == 'D'){
                b1 = 4;
            }
            else{
                b1 = 5;
            }
        }
    }
    for(int i = 0; i < s2.size(); i++){
        if(s2[i] - '0' <= 9 && s2[i] - '0' >= 0){
            a2 = a2 * 10 + s2[i] - '0';
        }
        else{
            if(s2[i] == 'A'){
                b2 = 1;
            }
            else if(s2[i] == 'B'){
                b2 = 2;
            }
            else if(s2[i] == 'C'){
                b2 = 3;
            }
            else if(s2[i] == 'D'){
                b2 = 4;
            }
            else{
                b2 = 5;
            }
        }
    }
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    if(a1 != a2){
        cout << 1000;
        return 0;
    }
    if(!(b1 <= 3 && b2 <= 3) && !(b2 >= 4 && b1 >= 4)){
        cout << 1100;
        return 0;
    }
    if(b1 != b2 + 1 && b2 != b1 + 1){
        cout << 1110;
        return 0;
    }
    cout << 1111;
    return 0;
}
