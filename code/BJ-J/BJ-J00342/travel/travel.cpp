#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1!="01"&&c1!="16")cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    bool f=false;
    bool k=false;
    char x=s1[2],y=s2[2];
    int a=int(x),b=int(y);
    if(x=='A'||x=='B'||x=='C'){
        if(y=='A'||y=='B'||y=='C'){
            f=true;
            if(a==b+1||a==b-1)k=true;
        }
    }
    if(x=='D'||x=='F'){
        if(y=='D'||y=='F'){
            f=true;
            if(a==b+2||a==b-2)k=true;
        }
    }
    if(f)cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if(k)cout<<1;
    else cout<<0;
    return 0;
}
