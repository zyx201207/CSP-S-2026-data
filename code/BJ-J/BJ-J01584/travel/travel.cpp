#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    getline(cin,s);
    if(s[0]==s[7]&&s[1]==s[8]){
        cout<<"1";
        if(s[3]==s[10]&&s[4]==s[11]){
            cout<<"1";
            if(s[5]=='A'&&s[12]=='B'||
               s[5]=='B'&&s[12]=='C'||
               s[5]=='A'&&s[12]=='C'||
               s[5]=='D'&&s[12]=='F'||
               s[12]=='A'&&s[5]=='B'||
               s[12]=='B'&&s[5]=='C'||
               s[12]=='A'&&s[5]=='C'||
               s[12]=='D'&&s[5]=='F'){
                cout<<"1";
                if(abs(s[12]-s[5])==1&&(s[5]!='C'&&s[12]!='D'||s[5]!='D'&&s[12]!='C')){
                    cout<<"1";
                }
                else cout<<'0';
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
