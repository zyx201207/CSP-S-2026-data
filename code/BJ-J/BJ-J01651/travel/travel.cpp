#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,z;
    ll cr,cx,pr,px;
    char zr,zx;

    cin>>c;
    cin>>z;
    cr=((c[0]-'0')*10+(c[1]-'0'));
    pr=((z[0]-'0')*10+(z[1]-'0'));
    zr=z[2];

    cin>>c;
    cin>>z;
    cx=((c[0]-'0')*10+(c[1]-'0'));
    px=((z[0]-'0')*10+(z[1]-'0'));
    zx=z[2];
    ll ans[5];
    if(cr==cx)ans[1]=1;
    else ans[1]=0;
    if(ans[1]==1&&pr==px)ans[2]=1;
    else ans[2]=0;
    if(ans[2]==1&&((zr>='D'&&zx>='D')||(zr<='C'&&zx<='C')))ans[3]=1;
    else ans[3]=0;
    if(ans[3]==1&&abs(zr-zx)==1)ans[4]=1;
    else ans[4]=0;
    for(ll i=1;i<=4;i++)cout<<ans[i];
    cout<<endl;
    return 0;
}
