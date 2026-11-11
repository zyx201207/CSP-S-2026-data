#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c)
    {
        cout<<"0000";
        return 0;
    }
    for(ll i=0;i<b.size();i++)
    {
        if(i!= b.size()-1)
        {
            if(b[i]!=d[i])
            {
                cout<<"1000";
                return 0;
            }
        }
        else
        {
            if(b[i]>='D'&&d[i]>='D' || d[i]<='C'&&b[i]<='C')
            {
                if(abs(b[i]-d[i])== 1)
                {
                    cout<<"1111";
                    return 0;
                }
                else
                {
                    cout<<"1110";
                    return 0;
                }
            }
            else
            {
                cout<<"1100";
                return 0;
            }
        }
    }
    return 0;
}
