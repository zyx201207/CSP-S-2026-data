#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool r=true;
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<2;i++)
    {
        if(a[i]!=c[i])
        {
            r=false;
        }
    }
    if(!r)
    {
        cout<<"0000";
    }
    else
    {
        cout<<1;
        for(int i=0;i<2;i++)
        {
            if(b[i]!=d[i])
            {
                r=false;
            }
        }
        if(!r)
        {
            cout<<"000";
        }
        else
        {
            cout<<1;
            if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
            {
                cout<<1;
                int k=b[2]-'0',l=d[2]-'0';
                if(abs(k-l)>1)
                {
                    cout<<0;
                }
                else
                {
                    cout<<1;
                }
            }
            else if((b[2]=='D'||b[2]=='F')&&(d[2]=='d'||d[2]=='F'))
            {
                cout<<"11";
            }
            else
            {
                cout<<"00";
            }
        }
    }
}
