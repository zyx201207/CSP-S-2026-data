#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5;
int a,b;
char c[N],d[N];
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>a>>c[1]>>c[2]>>c[3]>>b>>d[1]>>d[2]>>d[3];
    if(a==b)
    {
        cout<<"1";
        if(c[1]==d[1] && c[2]==d[2])
        {
            cout<<"1";
            if((c[3]<='C' && d[3]<='C') || (c[3]>'C' && d[3]>'C'))
            {
                cout<<"1";
                if(abs(c[3]-d[3])==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}