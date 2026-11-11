#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    char a=a2[2],b=b2[2];
    int a3=(a2[0]-'0')*10+a2[1]-'0',x,y,z;
    int b3=(b2[0]-'0')*10+b2[1]-'0';
    if(a1==b1){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(a3==b3){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(a<='C'&&(a-'0'==b-'0'+1||a-'0'==b-'0'-1)){
        cout<<1;
    }else if(a>='D'&&(a-'0'==b-'0'+2||a-'0'==b-'0'-2)){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
