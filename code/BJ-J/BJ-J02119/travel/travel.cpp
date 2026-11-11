#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int f(){
    if(s1[2]<'D'&&s2[2]<'D')return abs(s1[2]-s2[2])==1;
    return (s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D');
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))cout<<1<<f();
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
