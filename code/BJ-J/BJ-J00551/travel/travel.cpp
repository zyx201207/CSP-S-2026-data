#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string q,w,e,r;
    cin>>q>>w>>e>>r;
    if(q==e)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(w[0]==r[0]&&w[1]==r[1])cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if((w[2]<='C'&&r[2]<='C')||(w[2]>='D'&&r[2]>='D'))cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(abs(w[2]-r[2])==1)cout<<1;
    else cout<<0;
    return 0;
}
