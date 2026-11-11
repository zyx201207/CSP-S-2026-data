#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    char a[2],b[2],x[4],y[4];
    cin>>a>>x>>b>>y;
    char m[10]="ABCDF";
    char p[3],q[3];
    p[0]=x[0];
    q[0]=y[0];
    p[1]=x[2];
    q[1]=y[2];
    if (a[0] == b[0] && a[1] == b[1])
    {
        cout<<"1";
        if (x[0] == y[0] && x[1] == y[1])
        {
           cout<<"1";
           if (x[2] == m[0] && y[2] == m[1] || x[2] ==m[0] && y[2]==m[2])
           {
               cout<<"1";
               if (y[2]==m[1])
               {
                   cout<<"1";
               }
               else cout<<"0";
           }
           else if(x[2]==m[1] && y[2]==m[0] || x[2]==m[1] && y[2]==m[2])
           {
               cout<<"11";
           }
           else if (x[2]==m[1] && y[2]==m[0] || x[2]==m[1] && y[2]==m[2])
           {
               cout<<"1";
               if (y[2]==m[1])
               {
                   cout<<"1";
               }
               else cout<<"0";
           }
           else if (x[2]==m[4] && y[2]==m[5] || x[2]==m[5] && x[2]==m[4])
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
