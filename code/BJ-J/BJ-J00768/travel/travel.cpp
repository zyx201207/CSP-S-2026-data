#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
if(c1==c2) cout<<"1";
else{
    cout<<"0000";
    return 0;
}
if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
else{
    cout<<"000";
    return 0;
}
if((s1[2]==65||s1[2]==66||s1[2]==67)&&(s2[2]==65||s2[2]==66||s2[2]==67)) cout<<"1";
else{
    if((s1[2]==68||s1[2]==70)&&(s2[2]==68||s2[2]==70)) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
}
if((s1[2]==65&&s2[2]==66)||(s1[2]==66&&s2[2]==67)||(s1[2]==68||s2[2]==70)) cout<<"1";
else{
    cout<<"0";
    return 0;
}
return 0;
}