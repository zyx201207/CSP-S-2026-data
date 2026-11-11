#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2;
    int a1, a2, a3, a4;
    bool you = false, pai = false, ok1 = false, ok2 = false;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        a1 = 1;
        ok1 = true;
    }else{
        a1 = 0;
    }
    if(ok1 && s1[0] == s2[0] && s1[1] == s2[1]){
        a2 = 1;
        ok2 = true;
    }else{
        a2 = 0;
    }
    if(ok1&&ok2&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
        a3 = 1;
        if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
            you = true;
        }else{
            you = false;
        }
        pai = true;
    }else{
        a3 = 0;
    }
    if(ok1&&ok2&&pai&&you&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C'))){
        a4 = 1;
    }else if(pai&&!you){
        a4 = 1;
    }else{
        a4 = 0;
    }
    //cout << abs('s1[2]'-'s2[2]');
    //cout << 's1[2]';
    cout << a1 << a2 << a3 << a4;
    return 0;
}
