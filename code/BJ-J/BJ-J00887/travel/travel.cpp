#include<bits/stdc++.h>
using namespace std;
string x,y,u,v;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>y>>u>>v;
    if (x==u)
    {
        cout<<"1";
        string i=y.substr(0,2),j=v.substr(0,2);
        if (i==j)
        {
            cout<<"1";
            char c=y[2],d=v[2];
            if (c<='C'&&d<='C'||c>='D'&&d>='D')
            {
                cout<<"1";
                if ((abs(c-d))==1||(c=='F'||d=='F'))
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
