#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<"1";   //CHE XIANG
    else {
        cout<<"0000";
        return 0;
    }

    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";// TONG YI PAI
    else {
        cout<<"000";
        return 0;
    }

    int pai=0;
    if(s1[2]<='C'&&s2[2]<='C') pai=1;// TONG YI CE (ABC)
    if(s1[2]>='D'&&s2[2]>='D') pai=1;// TONG YI CE (DF)
    if(pai==0) {
        cout<<"00";
        return 0;
    }else cout<<1;

    int xl=0;
    if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D') xl=1;//DF
    if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A') xl=1;//AB
    if(s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B') xl=1;//BC
    cout<<xl;
    return 0;
}
