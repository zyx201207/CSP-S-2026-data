#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int k1,k2,n1,n2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        k1=1;
    }else{
        k1=2;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
        k2=1;
    }else{
        k2=2;
    }
    n1=s1[2]-'0';
    n2=s2[2]-'0';
    if(k1==k2){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(k1==2&&k2==2){
        cout<<1;
        return 0;
    }
    if(abs(n1-n2)==1){
        cout<<1;
    }else{
        cout<<"0";
    }
    return 0;
}
