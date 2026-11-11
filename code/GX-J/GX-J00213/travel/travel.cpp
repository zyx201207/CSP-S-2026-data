#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int cnt=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]==c[i])cnt++;
    }
    if(cnt==a.size())
    {
        cout<<"1";
        int idxsus=0;
        for(int i=0; i<b.size()-1; i++)
        {
            if(b[i]==d[i])idxsus++;
        }
        if(idxsus==2)
        {
            cout<<"1";
            if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')
            {
                cout<<"1";
                if(b[2]-1==d[2]||b[2]+1==d[2])
                {
                    cout<<"1";
                }
                else cout<<"0";
            }
            else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')
            {
                cout<<"11";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
