#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string seat_1,seat_2;
string a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
        cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    for(int i=0;i<s1.size()-1;i++){
        seat_1 += s1[i];
    }
    for(int j=0;j<s1.size()-1;j++){
        seat_2 += s2[j];
    }
    if(seat_1==seat_2){
        cout << 1;
    }
    else{
        cout << 0;
    }
    for(int i=0;i<s1.size();i++){
        if(s1[i]>='A'&&s1[i]<='Z'){
            a+=s1[i];
        }
    }
    for(int j=0;j<s2.size();j++){
        if(s2[j]>='A'&&s2[j]<='Z'){
            b+=s2[j];
        }
    }
/*
    if(a=='A'||a=='B'||a=='C'&&b=='A|'|b=='B'|| b=='C'){
            cout << 1;
    }
    else if(a=='D'|| a=='F'&&b=='D'||b=='F'){
            cout << 1;
    }
    else{
        cout << 0;
    }
*/
    cout << 10;
    return 0;
}