#include <bits/stdc++.h>
using namespace std;
string c1 , s1 , c2 , s2;
bool image(char cc1 , char cc2){
    if(cc1 >= 'A' && cc2 <= 'C' || cc1 >= 'D' && cc2 <= 'F'){
        return true;
    }else{
        return false;
    }
}
bool flag(char cc1 , char cc2){
    if(cc1 == 'A' && cc2 == 'B' || cc1 == 'B' && cc2 == 'A'){
        return true;
    }
    if(cc1 == 'C' && cc2 == 'B' || cc1 == 'B' && cc2 == 'C'){
        return true;
    }
    if(cc1 == 'D' && cc2 == 'F' || cc1 == 'F' && cc2 == 'D'){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }
    int cnt1 = s1[0] * 10 + s1[1];
    int cnt2 = s2[0] * 10 + s2[1];
    if(cnt1 == cnt2){
        cout << 1;
    }else{
        cout << "000";
        return 0;
    }
    char ans1 = s1[2] , ans2 = s2[2];
    if(image(ans1 , ans2)){
        cout << 1;
    }else{
        cout << "00";
        return 0;
    }
    if(flag(ans1 , ans2)){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}