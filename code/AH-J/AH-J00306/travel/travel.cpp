#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cc>>ss;
    if(c==cc){
        cout<<"1";
    }
    else{
        cout<<"0000";return 0;
    }
    if(s[0]==ss[0]&&s[1]==ss[1]){
        cout<<"1";
    }
    else{
        cout<<"000";return 0;
    }
    if(s[2]<='C'&&ss[2]<='C'||s[2]>'C'&&ss[2]>'C'){
        cout<<"1";
    }
    else{
        cout<<"00";return 0;
    }
    if(s[2]<='C'&&ss[2]<='C'){
        if(s[2]=='A'&&ss[2]=='C'||s[2]=='C'&&ss[2]=='A') cout<<"0";
        else cout<<"1";
    }
    else{
        cout<<"1";
    }
    return 0;
}
