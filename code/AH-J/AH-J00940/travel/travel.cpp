#include <bits/stdc++.h>
using namespace std;
bool panduan(string a,string b){
    if(a == "A"){
        if(b=="B"){
            return 1;
        }
    }
    if(a == "B"){
        if(b=="C"|| b=="A"){
            return 1;
        }
    }
    if(a == "C"){
        if( b == "B"){
            return 1;
        }
    }
    if(a == "D"){
        if (b =="F"){
            return 1;
        }
    }
    if(a == "F"){
        if (b == "D"){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int flag1 = 0;
    int flag2 = 0;
    string j,s;
    if(c1==c2){
        cout << "1";
    }
    if(c1 != c2){
        cout << "0";
    }
    if (s1[0] == s2[0] && s1[1] == s2[1]){
        cout << "1";
    }
    if(s1[0] != s2[0] || s1[0] != s2[0]){
        cout << "0";
    }
    if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
        flag1 = 1;
    }
    if (s1[2] == 'D' || s1[2] == 'F'){
        flag1 = 2;
    }
    if (s2[2] == 'A'|| s2[2] == 'B' || s2[2] == 'C'){
        flag2 = 1;
    }
    if (s2[2] == 'D' || s2[2] == 'F'){
        flag2 = 2;
    }
    if (flag1 == flag2){
        cout << "1";
    }
    if (flag1 != flag2){
        cout << "0";
    }
    j = s2[2];
    s = s2[2];
    if (panduan(j,s)){
        cout << "1";
    }
    if (!panduan(j,s)){
        cout << "0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
