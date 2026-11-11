#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b;
    cin>>a;
    string s,t;
    cin>>s;
    cin>>b;
    cin>>t;
    if(a==b){
        cout<<"1";
        if((s[0]-'0')*10+s[1]-'0'==(t[0]-'0')*10+t[1]-'0'){
            cout<<"1";
            if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(t[2]=='A'||t[2]=='B'||t[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(t[2]=='D'||t[2]=='F'))){
                cout<<"1";
                if((s[2]-'A'-1==t[2]-'A')||(t[2]-'A'-1==s[2]-'A')||(t[2]-'A'==s[2]-'A')){
                    cout<<"1";
                }else{
                cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
    fclose(stdin);
    fclose(stdout);
}
