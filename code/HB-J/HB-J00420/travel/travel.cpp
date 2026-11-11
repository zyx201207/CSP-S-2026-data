#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string c1, s1, c2, s2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2){
        cout << "0000";
        return 0;
    }
    cout << '1';
    if(s1[0] == s2[0] && s1[1] == s2[1]){
        cout << '1';
    }else{
        cout << "000";
        return 0;
    }
    if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')){
        cout << '1';
    }else{
        cout << "00";
        return 0;
    }
    char t1 = s1[2], t2 = s2[2];
    if(t1 > t2) swap(t1, t2);
    if(t1 <= 'C'){
        if((t1 == 'A' && t2 == 'B') || (t1 == 'B' && t2 == 'C')) cout << '1';
        else cout << '0';
    }else{
        if(t1 == 'D' && t2 == 'F') cout << '1';
        else cout << '0';
    }
    return 0;
}
