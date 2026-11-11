#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool tc=false,tx=false,th=false;
    if(c1[0]!='0'&&c1[1]!='1'||c1[0]!='1'&&c1[1]!='6'&&c2[0]!='0'&&c2[1]!='1'||c2[0]!='1'&&c2[1]!='6'&&c1[0]==c2[0]&&c1[1]==c2[1]) {cout<<1;tx==true;}
        else {cout<<0<<0<<0<<0;return 0;}
    if(s1[0]==s2[0]&&s1[1]==s2[1]){cout<<1;th=true;}
        else {cout<<0<<0<<0;return 0;}
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='C'||s2[2]=='A'||s2[2]=='B'&&th==true) {cout<<1;tc=true;}
        else if(s1[2]=='D'&&s2[2]!='D'||s1[2]=='F'&&s2[2]!='F'&&s2[2]=='D'||s2[2]=='F'&&th==true) {cout<<1<<1;tc=true;return 0;}
            else cout<<0;
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1&&tc==true) cout<<1;else cout<<0;
    return 0;
}
