#include<iostream>
using namespace std;

int c1,c2;
string s1,s2;

bool check0(){
    //是否同一排
    return (s1[0]==s2[0] && s1[1]==s2[1]);
}

bool check1(){
    //是否同一侧
    if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
        if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C')  return true;
    }
    else{
        if(!(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'))  return true;
    }
    return false;
}

bool check2(){
    //是否相邻
    if(s1[2]+1==s2[2] || s2[2]+1==s1[2])    return true;
    return false;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    // frepopen
    cin >> c1 >> s1 >> c2 >> s2;
    // cout << check1() << endl;
    string ans = "0000";
    if(c1 == c2)    ans[0] = '1';
    if(c1==c2 && check0())  ans[1] = '1';
    if(c1==c2 && check0() && check1())  ans[2] = '1';
    if(c1==c2 && check0() && check1() && check2())  ans[3] = '1';
    cout << ans << endl;
    return 0;
}