#include <bits/stdc++.h>
using namespace std;


string c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1>>s1>>c2>>s2;
    if(c1<"01"||c1>"18"||c2<"01"||c2>"18"||c1=="01"||c1=="16"||c2=="01"||c2=="16"){
        cout << "0000";
        return 0;
    }
    if(s1[0]<'0'||s1[0]>'1'||s2[0]<'0'||s2[0]>'1'){
        cout << "0000";
        return 0;
    }
    if(s1[1]<'1'||s1[1]>'8'||s2[1]<'1'||s2[1]>'8'){
        cout << "0000";
        return 0;
    }
    if(s1[2]<'A'||s1[2]>'F'||s1[2]=='E'||s2[2]<'A'||s2[2]>'F'||s2[2]=='E'){
        cout << "0000";
        return 0;
    }
    if(c1==c2)cout <<1;
    else {
        cout << "0000";
        return 0;
    }
    if(s1[0]==s2[0]){
        if(s1[1]==s2[1]){
            cout <<1;
        }
        else{
            cout << "000";
            return 0;
        }
    }
    else {
        cout << "000";
        return 0;
    }
    if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
        cout << 1;
        if(s1[2]=='A'&&s2[2]=='C'){
            cout << 0;
            return 0;
        }
        else if(s1[2]=='C'&&s2[2]=='A'){
            cout << 0;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
        cout <<11;
        return 0;
    }
    else{
        cout << "00";
        return 0;
    }
    return 0;
}

