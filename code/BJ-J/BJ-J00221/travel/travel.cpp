#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

bool instr(char c, string s){
    for (int ch : s){
        if (c == ch){
            return 1;
        }
    }
    return 0;
}

bool xl(char c1, char c2){
    if (instr(c1, "ABC")){
        if ((c1 == 'A'  &&  c2 == 'C') || (c1 == 'C'  &&  c2 == 'A')){
            return 0;
        }
        return 1;
    }
    else {
        return 1;
    }
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>c1>>s1>>c2>>s2;
    if (c1 == c2){
        if (s1[0] == s2[0]  &&  s1[1] == s2[1]){
            if ((instr(s1[2], "ABC") && instr(s2[2], "ABC")) || (instr(s1[2], "DF") && instr(s2[2], "DF"))){
                if (xl(s1[2], s2[2])){
                    cout<<"1111"<<endl;
                }
                else {
                    cout<<"1110"<<endl;
                }
            }
            else {
                cout<<"1100"<<endl;
            }
        }
        else {
            cout<<"1000"<<endl;
        }
    }
    else {
        cout<<"0000"<<endl;
    }

    return 0;
}
