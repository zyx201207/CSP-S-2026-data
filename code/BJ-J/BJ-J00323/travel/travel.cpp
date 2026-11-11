#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    int c1,c2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    int a=s1[2],b=s2[2];
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            cout<<"1";
            if(s1[2]<='C' && s2[2]<='C' || s1[2]>'C' && s2[2]>'C')
            {
                cout<<"1";
                if(a==b+1 || a==b-1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"0"<<"0";
        }
        else cout<<"0"<<"0"<<"0";
    }
    else cout<<"0"<<"0"<<"0"<<"0";
    return 0;
}