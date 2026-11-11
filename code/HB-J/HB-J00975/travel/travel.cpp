#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r,rt,x,xt;
    cin>>r>>rt>>x>>xt;
    if(r==x)
    {
        cout<<1;
        if(rt[0]==xt[0]&&rt[1]==xt[1])
        {
            cout<<1;
            if((rt[2]<='C'&&xt[2]<='C')||(rt[2]>='D'&&xt[2]>='D'))
            {
                cout<<1;
                if(abs(int(rt[2])-int(xt[2]))==1)
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
