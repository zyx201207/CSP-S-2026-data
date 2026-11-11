#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }
    else if(s1[1]!=s2[1] or s1[0]!=s2[0]){
        cout<<"1000";
    }
    else if((s1[2]>'C' and s2[2]<'D') or (s1[2]<'D' and s2[2]>'C')){
        cout<<"1100";
    }
    else if((s1[2]=='C' and s2[2]=='A') or (s1[2]=='A' and s2[2]=='C')){
        cout<<"1110";
    }
    else{
        cout<<"1111";
    }
    return 0;
    }
