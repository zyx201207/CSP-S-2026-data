#include <bits/stdc++.h>
using namespace std;
void solve(string c1,string c2,string s1,string s2){
    string t = "1";
    if(c2[0] != s2[0] || c2[1] != s2[1]){
        cout << "1000" << endl;
        return;
    }
    if(c2[2] > s2[2]){
        string d = c2;
        c2 = s2;
        s2 = d;
    }
    if(c2[2] == 'D' && s2[2] == 'F') t = "1111";
    else if(c2[2] == 'A'){
        if(s2[2] == 'B') t = "1111";
        else if(s2[2] == 'C') t = "1110";
    }else if(c2[2] == 'B' && s2[2] == 'C') t = "1111";
    if(t == "1"){
        cout << "1100" << endl;
        return;
    }else{
        cout << t << endl;
        return;
    }
}
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    string c1,c2,s1,s2;
    cin >> c1 >> c2 >> s1 >> s2;
    if(c1 != s1){
        cout << "0000" << endl;
        return 0;
    }
    solve(c1,c2,s1,s2);
    return 0;
}