#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1c,s1z,s2c,s2z;
    cin >> s1c >> s1z >> s2c >> s2z;
    if(s1c == s2c){
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }

    if(s1z[0] == s2c[0] && s1z[1] == s2z[1]){
        cout << 1;
    }else{
        cout << "000";
        return 0;
    }

    if(s1z[2] >= 'D' && s2z[2] <= 'C' || s1z[2] <= 'C' && s2z[2] >= 'D'){
        cout << "00";
        return 0;
    }else{
        cout << 1;
    }

    int s1 = s1z[2],s2 = s2z[2];

    if(s1 - s2 == 1 && s1z[2] != 'D' || s2 - s1 == 1 && s2z[2] != 'D'){
        cout << 1;
    }else if(s1-s2 == 2 && s1z[2] == 'F' || s2-s1 == 2 && s2z[2] == 'F'){
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}
