#include<bits/stdc++.h>
using namespace std;
string a,b,s,v;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s>>b>>v;
    if(a!=b) cout<<"0000";
    else
    {
        cout<<1;
        if(s[0]==v[0]&&s[1]==v[1]) cout<<1;
        else
        {
            cout<<"000";
            return 0;
        }
        if(s[2]=='A'||s[2]=='B'||s[2]=='C')
        {
            if(v[2]=='A'||v[2]=='B'||v[2]=='C') cout<<1;
            else
            {
                cout<<"00";
                return 0;
            }
        }
        else
        {
            if(v[2]=='C'||v[2]=='D') cout<<1;
            else
            {
                cout<<"00";
                return 0;
            }
        }
        if(s[2]=='C'||s[2]=='D'&&v[2]=='C'||v[2]=='D')
        {
            cout<<0;
        }
        else
        {
            if(s[2]-'0'+1==v[2]-'0'||s[2]-'0'-1==v[2]-'0') cout<<1;
            else cout<<0;
        }
    }
    return 0;
}
