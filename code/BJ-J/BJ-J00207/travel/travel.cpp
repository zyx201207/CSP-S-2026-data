#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll a,b;
    string x,y;
    cin>>a>>x>>b>>y;
    if(a==b)
    {
        cout<<1;
        if(x[0]==y[0] && x[1]==y[1])
        {
            cout<<1;
            if((x[2]>'C' && y[2]>'C') || (x[2]<='C' && y[2]<='C'))
            {
                cout<<1;
                if(abs(x[2]-y[2])==1) cout<<1;
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    cout<<endl;
    return 0;
}
