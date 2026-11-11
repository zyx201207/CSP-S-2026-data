#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string s,d;
    cin>>a>>s>>b>>d;
    if(a==b){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }if(s[1]==d[1])cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    if(s[2]<='D'&&s[2]>='F'&&d[2]<='D'&&d[2]>='F'||s[2]<='C'&&s[2]>='A'&&d[2]<='C'&&d[2]>='A'){
        cout<<1;
    }else{
         cout<<"00";
         return 0;
    }
    if(s[2]=='A'||s[2]=='B'||s[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C'||s[2]=='D'||s[2]=='F'&&d[2]=='D'||d[2]=='F'){
        if(s[2]=='D'||s[2]=='F'&&d[2]=='D'||d[2]=='F'){
            cout<<1;
        }else if(s[2]=='A'&&d[2]!='C'||s[2]=='C'&&d[2]!='A'){
            cout<<1;
        }else{
            cout<<"0";
        }
    }

    return 0;
}
