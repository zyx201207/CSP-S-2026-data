#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string n,m;
    cin>>a>>n>>b>>m;
    if(n[2]=='D')
    {
        n[2]='E';
    }
    if(m[2]=='D')
    {
        m[2]='E';
    }
    if(a==b)
    {
        if(n[0]==m[0] and n[1]==m[1])
        {
            if(((n[2]=='A' or n[2]=='B' or n[2]=='C')and(m[2]=='A' or m[2]=='B' or m[2]=='C'))or
               ((n[2]=='D' or n[2]=='F')and(m[2]=='D' or m[2]=='F')))
            {
                if(n[2]+1==m[2] or n[2]-1==m[2])
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else
            {
                cout<<"1100";
            }
        }
        else
        {
            cout<<"1000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
