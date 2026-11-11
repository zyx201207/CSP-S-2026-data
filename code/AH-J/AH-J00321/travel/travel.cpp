#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pai(string z1,string z2){
    if(z1[0]==z2[0] && z1[1]==z2[1]) return 1;
    return 0;
}
bool ce(string z1,string z2){
    char z3=z1[2],z4=z2[2];
    if((z3=='A' || z3=='B' || z3=='C') && (z4!='D' && z4!='E')) return 1;
    if((z3=='D' || z3=='E') && (z4!='A' && z4!='B' && z4!='C')) return 1;
    return 0;
}
bool ling(string z1,string z2){
    int z3=z1[2]-'A'+1,z4=z2[2]-'A'+1;
    if(abs(z3-z4)==1 && ce(z1,z2)==1) return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string ans="";
    if(c1==c2) ans+='1';
    else ans+='0';
    if(c1==c2 && pai(s1,s2)==1) ans+='1';
    else ans+='0';
    if(c1==c2 && pai(s1,s2)==1 && ce(s1,s2)==1) ans+='1';
    else ans+='0';
    if(c1==c2 && pai(s1,s2)==1 && ce(s1,s2)==1 && ling(s1,s2)==1) ans+='1';
    else ans+='0';
    cout<<ans;
}
