#include <bits/stdc++.h>>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int s11[5],s22[5];
    if(c1==c2) cout<<"1";
    else{
        cout<<"0000";

    }
    for(int i=0;i<=2;i++){
       s11[i]=s1[i];
       s22[i]=s2[i];
    }
    if(c1==c2){
    if(s11[1]==s22[1]) cout<<1;
    else cout<<"0";
    if(s11[1]==s22[1]){
        if((s11[2]=='A'||'B'||'C'&&s22[2]=='A'||'B'||'C')||(s11[2]=='D'||'F'&&s22[2]=='D'||'F')){
                cout<<"1";}
                else cout<<"0";
         if(s11[2]+1==s22[2]||s22[2]-1==s22[2]||s11[2]+2==s22[2]||s22[2]+2==s22[2]){
                cout<<"1";}
                else cout<<"0";
    }
        else cout<<"0";

}}



