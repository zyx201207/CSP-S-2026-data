#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ans","w",stdout);
    int c1,c2,s11,s22;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else if(s1[0]!=s2[0] || s1[1]!=s2[1]) cout<<1000;
    else {
        if(s1[2]<=67) s11=s1[2]-64;
        else s11=(s1[2]=='D'?11:12);
        if(s2[2]<=67) s22=s2[2]-64;
        else s22=(s2[2]=='D'?11:12);
        if(s11-s22>=5 || s11-s22<=-5) cout<<1100;
        else if(s11-s22==1 || s11-s22==-1) cout<<1111;
        else cout<<1110;
    }
    return 0;
}
