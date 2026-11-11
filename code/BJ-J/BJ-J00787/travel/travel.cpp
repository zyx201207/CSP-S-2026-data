#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5];
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)a[0]=1;
    if(a[0] && s1[1]==s2[1])a[1]=1;
    if(a[1] && ( (s1[2]<='C' && s2[2]<='C') ||(s1[2]>'C' && s2[2]>'C') ))a[2]=1;
    if(a[2] && ((s1[2]-s2[2]==1) || s2[2]-s1[2]==1 ) )a[3]=1;
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
