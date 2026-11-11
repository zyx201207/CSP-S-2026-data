#include<bits/stdc++.h>
using namespace std;
inline bool near(char a, char b){
    if((a == 'D' && b == 'F') || (a == 'F' && b == 'D')){
        return 1;
    }
    if((a == 'A' && b == 'B') || (a == 'B' && b == 'A')){
        return 1;
    }
    if((a == 'C' && b == 'B') || (a == 'B' && b == 'C')){
        return 1;
    }
    return 0;
}
inline bool ss(char a, char b){
    if(a == 'A' || a == 'B' || a == 'C'){
        if(b == 'A' || b == 'B' || b == 'C'){
            return 1;
        }else{
            return 0;
        }
    }
    if(a == 'D' || a == 'F'){
        if(b == 'D' || b == 'F'){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, a2, b, b2;
    cin >> a >> a2 >> b >> b2;
    char s1, s2;
    s1 = (char)a2[2]; s2 = (char)b2[2];
    if(a == b) cout << 1;
    else cout << 0;
    if(a == b && b2[0] == a2[0] && b2[1] == a2[1]) cout << 1;
    else cout << 0;
    if(a == b && b2[0] == a2[0] && b2[1] == a2[1] && ss(s1, s2)) cout << 1;
    else cout << 0;
    if(a == b && b2[0] == a2[0] && b2[1] == a2[1] && near(s1, s2)) cout << 1;
    else cout << 0;
    return 0;
}
