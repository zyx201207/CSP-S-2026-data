#include<bits/stdc++.h>
using namespace std;
long long cx,cy,zx,zy;
char hx,hy;
string sx,sy;
bool b[4];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>cx>>sx>>cy>>sy;
    zx=(sx[0]-'0')*10+(sx[1]-'0');
    zy=(sy[0]-'0')*10+(sy[1]-'0');
    hx=sx[2];
    hy=sy[2];
    b[1]=(cx==cy);
    b[2]=(b[1]&(zx==zy));
    b[3]=(b[2]&((hx<='C')==(hy<='C')));
    b[4]=(b[3]&((hx!='A' && hx!='C') || (hy!='A' && hy!='C')));
    cout<<b[1]<<b[2]<<b[3]<<b[4];
    return 0;
}
