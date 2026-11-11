#include <bits/stdc++.h>
using namespace std;
int main(){
    string c,cc;
    char s[5],ss[5];
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
cin >> c >> s[1]>>s[2]>>s[3] >> cc>>ss[1] >> ss[2]>>ss[3];
    if(c==cc) cout << "1";
    else{
    cout << "0000";
    return 0;
    }
    if((s[1]==ss[1])&&(s[2]==ss[2])) cout << "1";
    else{
    cout <<"000";
    return 0;}
    if((s[3]<='C'&&ss[3]<='C')||s[3]>='D'&&ss[3]>='D') cout << "1";
    else{cout <<"00";
    return 0;}
    if(s[3]-1==ss[3]||ss[3]-1==s[3]||(s[3]=='F'||ss[3]=='F')&&(s[3]=='D'||ss[3]=='D')){
    cout << "1";
}
    else cout << "0";
    return 0;
}
