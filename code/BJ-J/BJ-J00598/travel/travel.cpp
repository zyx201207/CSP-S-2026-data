#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s>>d>>f;
    if(a==d){
        cout<<1;
        if(s[0]==f[0] && s[1]==f[1]){
            cout<<1;
            if((s[2]>='A' && s[2]<='C' && f[2]>='A' && f[2]<='C') || ((s[2]=='D' || s[2]=='F') && (f[2]=='D' && f[2]=='F'))){
                cout<<1;
                if((s[2]=='A' && f[2]=='B') || (s[2]=='B' && f[2]=='C') || (s[2]=='D' && f[2]=='F') || (s[2]=='B' && f[2]=='A') || (s[2]=='C' && f[2]=='B') || (s[2]=='F' && f[2]=='D')){
                    cout<<1;
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";

    return 0;
}
