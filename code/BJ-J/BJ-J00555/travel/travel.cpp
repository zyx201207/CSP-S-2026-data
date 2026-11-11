#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if (c1==c2){
        cout<<1;
        if (s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            bool a,b;
            if (s1[2]=='A' || s1[2]=='B' || s1[2]=='C')a=1;
            else a=0;
            if (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')b=1;
            else b=0;
            if (a==b){
                cout<<1;
                if ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='C') || (s1[2]=='D' && s2[2]=='F') || (s2[2]=='A' && s1[2]=='B') || (s2[2]=='B' && s1[2]=='C') || (s2[2]=='D' && s1[2]=='F') ){
                    cout<<1;
                }
                else {
                    cout<<0;
                }
            }
            else {
                cout<<0;
                cout<<0;
            }
        }
        else {
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}
