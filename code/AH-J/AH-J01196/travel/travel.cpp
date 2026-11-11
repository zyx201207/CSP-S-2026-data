#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char x=s1[2],y=s2[2];
    if(x>='A'&&x<='C'&&y>='A'&&y<='C'||x>='D'&&x<='F'&&y>='D'&&y<='F'){
        cout<<1;
    }else {
        cout<<"00";
        return 0;
    }
    if(x=='D'&&y=='F'||x=='F'&&y=='D'){
        cout<<1;
    }else if(x=='A'&&y=='B'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B'){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
