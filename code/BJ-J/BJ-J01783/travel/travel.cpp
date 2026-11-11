#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c[2];
char s[6];
cin>>c[0]>>s[0]>>s[1]>>s[2]>>c[1]>>s[3]>>s[4]>>s[5];
    if(s[2]=='D'){
            s[2]++;
    }
    if(s[5]=='D'){
            s[5]++;
            cout<<s[5];
    }
if(c[0]!=c[1]){
    cout<<"0"<<"0"<<"0"<<"0";
}else if(s[0]!=s[3] or s[1]!=s[4]){
    cout<<"1"<<"0"<<"0"<<"0";
}else if(s[2]+s[5] <='B'+'C' or  s[2]+s[5]=='E'+'F'){
    if(s[2]-s[5]==1 or s[5]-s[2]==1){
        cout<<"1"<<"1"<<"1"<<"1";
    }else{
        cout<<"1"<<"1"<<"1"<<"0";
    }
}else{
    cout<<"1"<<"1"<<"0"<<"0";
}
}