#include<bits/stdc++.h>
using namespace std;
int main(){
    string c1,s1,c2,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0] && c1[1]==c2[1]) cout<<1;
    else cout<<0;

    if(c1[0]==c2[0] && c1[1]==c2[1] && s1[0]==s[0] && s1[1]=s2[1]) cout<<1;
    else cout<<0;

    if(c1[0]==c2[0] && c1[1]==c2[1] && s1[0]==s[0] && s1[1]=s2[1]){
        if(s1[2]<'D'&&s2[2]<'D' || s1[2]>'C'&&s2[2]>'C') cout<<1;
        else cout<<0;
    }else cout<<0;

    if(c1[0]==c2[0] && c1[1]==c2[1] && s1[0]==s[0] && s1[1]=s2[1]){
        if(s1[2]<'D'&&s2[2]<'D' || s1[2]>'C'&&s2[2]>'C'){
            if(int(s2[2])-int(s1[2])==1 || int(s2[2])-int(s1[2])==-1) cout<<1;
            else cout<<0;
        }else cout<<0;
    }else cout<<0;
    return 0;
}