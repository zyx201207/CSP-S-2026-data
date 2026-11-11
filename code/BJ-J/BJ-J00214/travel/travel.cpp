#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>s1>>c2>>s2;
    char a == s1[2], b == s2[2];
    if(c1==c2)
        cout<<1;
    else
        cout<<0;
    if(s1[1]==s2[1] && s1[0]==s2[0]){
        cout<<1;
        if(a<='C' && b<='C' || a>='D' && b>='D'){
            cout<<1;
            if(a<='B' && b<='B' || a>='D' && b>='D' || a>='B' && b>='B')
                cout<<1;
            else
                cout<<0;
        }
        else
            cout<<0<<0;
    }
    else
        cout<<0<<0<<0;
    return 0;
}