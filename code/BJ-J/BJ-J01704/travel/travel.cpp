#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1[5],s1[5],c2[5],s2[5];
    cin>>c1>>s1>>c2>>s2;
    int rr1=(c1[0]-'0')*10+(c1[1]-'0'),xx1=(c2[0]-'0')*10+(c2[1]-'0');
    if(rr1==xx1){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    rr1=(s1[0]-'0')*10+(s1[1]-'0'),xx1=(s2[0]-'0')*10+(s2[1]-'0');
    if(rr1==xx1){
        cout<<1;
    }
    else {
        cout<<"000";
        return 0;
    }
    char r=s1[2],x=s2[2];
    if((r<='C'&& x<='C')||(r>'C'&&x>'C'))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((r>'C'&&x>'C')||(r-x==1||x-r==1))cout<<1;
    else cout<<0;
    return 0;
}