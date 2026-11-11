#include<bits/stdc++.h>
using namespace std;
string rx,rz,xz,xx;
int n=4,r,x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rx>>rz>>xx>>xz;
    if(rx==xx)
    {
        cout<<1;
        n--;
        if(rz[1]==xz[1]&&rz[0]==xz[0])
        {
            cout<<1;
            n--;
            r=rz[2]-'A';
            x=xz[2]-'A';
            if((r>2&&x>2)||(r<3&&x<3))
            {
                cout<<1;
                n--;
                if(max(r,x)-min(r,x)==1)
                {
                    cout<<1;
                    n--;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<0;
    return 0;
}
