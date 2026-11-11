#include <iostream>
using namespace std;
int gd(string s){
    return ('A'<=s[2] and s[2]<='C');
}
int main(){
    #if 01
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #endif // freopen
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) {cout<<"0000";return 0;}
    if(s1[0]!=s2[0] or s1[1]!=s2[1]) {cout<<"1000";return 0;}
    if(gd(s1)!=gd(s2)) {cout<<"1100";return 0;}
    if((s1[2]=='A' and s2[2]=='C') or (s1[2]=='C' and s2[2]=='A')) {cout<<"1110";return 0;}
    cout<<"1111";
}
