#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,z,cc,zz;
    cin>>c>>z>>cc>>zz;
    if(c==cc)
    {
        cout<<1;
        if(z.substr(0,2)==zz.substr(0,2))
        {
            cout<<1;
            if(z[2]<='C'&&zz[2]<='C'||z[2]>='D'&&zz[2]>='D')
            {
                cout<<1;
                if(abs(z[2]-zz[2])==1)
                    cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
