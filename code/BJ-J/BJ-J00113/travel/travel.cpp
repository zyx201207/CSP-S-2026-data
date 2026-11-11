#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char a1,a2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    cin>>s;
    c1 = s[0]-'0';
    c1 = c1*10;
    c1 += s[1]-'0';
    cin>>s;
    s1 = s[0]-'0';
    s1 = s1*10;
    s1 += s[1]-'0';
    a1 = s[2];
    cin>>s;
    c2 = s[0]-'0';
    c2 = c2*10;
    c2 += s[1]-'0';
    cin>>s;
    s2 = s[0]-'0';
    s2 = s2*10;
    s2 += s[1]-'0';
    a2 = s[2];
    if(c1 != c2){
        cout<<"0000";
        return 0;
    }
    if(s1 != s2){
        cout<<"1000";
        return 0;
    }
    if(((a1 == 'A' || a1 == 'B' || a1 == 'C') && (a2 == 'A' || a2 == 'B' || a2 == 'C')) ||
       ((a1 == 'D' || a1 == 'F') && (a2 == 'D' || a2 == 'F'))){
        if((a1 == 'A' && a2 == 'B') || (a2 == 'A' && a1 == 'B')){
            cout<<"1111";
            return 0;
        }
        if((a1 == 'B' && a2 == 'C') || (a2 == 'B' && a1 == 'C')){
            cout<<"1111";
            return 0;
        }
        if((a1 == 'D' && a2 == 'F') || (a2 == 'D' && a1 == 'F')){
            cout<<"1111";
            return 0;
        }
        cout<<"1110";
        return 0;
    }
    cout<<"1100";
    return 0;
}
