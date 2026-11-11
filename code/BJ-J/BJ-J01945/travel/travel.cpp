#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int flag;
signed main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
//ios::sync_with_stdio(0);
//cin.tie(0);cout.tie(0);
cin>>c1>>s1>>c2>>s2;
flag=1;
for(int i=0;i<c1.size();i++){
    if(c1[i]!=c2[i]){
        cout<<"0000";
        flag=0;
        break;
    }
}
if(flag){
        cout<<"1";
        for(int i=0;i<s1.size()-1;i++){
            if(s1[i]!=s2[i]){
            cout<<"000";
            flag=0;
            break;
        }
    }
}
if(flag){
    cout<<"1";
    if(s1[2]>'C'&&s2[2]>'C'){
        cout<<"11";
    }
    else if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
        cout<<"1";
        if(s1[2]=='A'&&s2[2]=='C'){
            cout<<"0";
        }
        else if(s1[2]=='C'&&s2[2]=='A'){
            cout<<"0";
        }
        else{
            cout<<"1";
        }
    }
    else{
        flag=0;
        cout<<"00";
    }
}
return 0;
}
