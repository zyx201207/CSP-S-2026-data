#include <bits/stdc++.h>
using namespace std;
int main(){
    feropen("travel.in","r",stdin);
    feropen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2 && c1<17 && c2<17){
        cout << "1";
    }
    else{
        cout << "0000";
        return 0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout << "11";
    }
    else{
        cout << "0";
    }
    if(s1[3]<'C' && s2[3]<'C'){
        if(s1[3]-'1'==s2[3]){
            cout << "1";
            break;
        }
        if(s1[3]+'1'==s2[3]){
            cout << "1";
        }
    }
    return 0;
}
