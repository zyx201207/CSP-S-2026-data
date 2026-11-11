#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char t=s1[2],t2=s2[2];
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    int a,b,a2,b2;
    a=s1[0]-'0';
    b=s2[0]-'0';
    a2=s1[1]-'0';
    b2=s2[1]-'0';
    if(a==b && a2==b2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }

    if(t<='C' && t2<='C' || t>='D'&& t2>='D'){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(int(t)-1==int(t2) || int(t2)-1==int(t)){
        cout<<1;
    }else cout<<0;
    return 0;
}
