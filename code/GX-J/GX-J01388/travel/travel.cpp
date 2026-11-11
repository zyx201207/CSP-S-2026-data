#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c)
        cout<<"1";
    else
        cout<<"0";


    if(b[1]==d[1] and b[0]==d[0])
        cout<<"1";
    else
        cout<<"0";


    if(b[1]==d[1] and b[0]==d[0])
    {
        if(('A'<=b[2]<='C' and 'A'<=d[2]<='C') or ('C'<=b[2]<='D' and 'C'<=d[2]<='D'))
            cout<<"1";
        else
            cout<<"0";
    }
    else
        cout<<"0";


    if(b[1]==d[1] and b[0]==d[0])
    {
        if(('A'<=b[2]<='C' and 'A'<=d[2]<='C') or ('C'<=b[2]<='D' and 'C'<=d[2]<='D'))
        {
            if((int)b[2]+1==(int)d[2] or (int)d[2]+1==(int)b[2])
            {
                if(b[2]=='C' and d[2]=='D' and b[2]=='D' and d[2]=='C')
                    cout<<"0";
                else
                    cout<<"1";
            }
            else
            cout<<"0";
        }
        else
            cout<<"0";
    }
    else
        cout<<"0";
    return 0;
}
