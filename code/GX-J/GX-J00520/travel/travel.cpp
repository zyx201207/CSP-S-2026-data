#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1, c2, s1, s2;
    char ss1, ss2;
    cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
    if(c1==c2){
        cout<<1;
    }

    else{
        cout<<"0000";
        return 0;
    }

    if(s1==s2){
        cout<<1;
    }

    else{
        cout<<"000";
        return 0;
    }

    if((ss1<='C'&&ss2>='D')||(ss1>='D'&&ss2<='C')){
        cout<<"00";
        return 0;
    }

    else{
        cout<<1;
    }

    if(((int)ss1+1==(int)ss2)||((int)ss2+1==(int)ss1)){
        cout<<1;
    }

    else if((ss1=='D'&&ss2=='F')||(ss1=='F'&&ss2=='D')){
        cout<<1;
    }

    else cout<<0;

    return 0;
}
