#include <bits/stdc++.h>

using namespace std;
struct Node
{
    string cx;
    string sl;
}node[5];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>node[1].cx>>node[1].sl;
    cin>>node[2].cx>>node[2].sl;

    int sa=0,sb=0;
    char ca,cb;
    for(int i=0;i<=1;i++)
    {
        sa=sa*10+node[1].sl[i]-'0';
        sb=sb*10+node[2].sl[i]-'0';
    }
    ca=node[1].sl[2];
    cb=node[2].sl[2];
    if(node[1].cx==node[2].cx)
    {
        cout<<'1';
        if(sa==sb)
        {
            cout<<'1';
            if((ca>='A'&&ca<='C')&&(cb>='A'&&cb<='C')||(ca>='D'&&ca<='F')&&(cb>='D'&&cb<='F'))
            {
                cout<<'1';
                if(abs(ca-cb)==1&&ca<='C')
                    cout<<'1';
                else if(abs(ca-cb)==2&&ca>='D')
                    cout<<'1';
                else
                    cout<<'0';
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
