#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string ca,cb;
    cin>>a;cin>>ca;cin>>b;cin>>cb;
    if(a==b)
    {
        cout<<1;
        if(ca.substr(0,2)==cb.substr(0,2))
        {
            cout<<1;
            if((ca[2]=='A'||ca[2]=='B'||ca[2]=='C')&&(cb[2]=='A'||cb[2]=='B'||cb[2]=='C'))
            {
                cout<<1;
                if(ca[2]==cb[2]+1||ca[2]+1==cb[2])cout<<1;
                else cout<<0;
            }
            else if(ca[2]=='D'||ca[2]=='F')
            {
                if(cb[2]=='D'||cb[2]=='F')cout<<11;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
