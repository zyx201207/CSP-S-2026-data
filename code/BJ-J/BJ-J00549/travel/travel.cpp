#include <bits/stdc++.h>
using namespace std;
int main(){
    string c1,s1,c2,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
    }
    int rs=((s1[0]-'0')*10+(s1[1]-'0')),xs=((s2[0]-'0')*10+(s2[1]-'0'));
    char rz=s1[2],xz=s2[2];
    if(c1==c2&&rs==xs){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&rs==xs&&(rz=='D'&&xz=='F'||rz=='F'&&xz=='D'||rz=='A'&&xz=='B'||rz=='A'&&xz=='C'||rz=='B'&&xz=='A'||rz=='B'&&xz=='C'||rz=='C'&&xz=='A'||rz=='C'&&xz=='B')){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&rs==xs&&(rz=='D'&&xz=='F'||rz=='F'&&xz=='D'||rz=='A'&&xz=='B'||rz=='B'&&xz=='A'||rz=='B'&&xz=='C'||rz=='C'&&xz=='B')){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}