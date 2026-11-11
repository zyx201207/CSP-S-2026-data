#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[3355306],k,a[3355306],t[3355306];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    cin>>k;
    for(int i=1;i<=2*k;i++)cin>>a[i]>>t[i];
    for(int i=1;i<=q;i++)
    {
        cout<<t[i]+w[i]-1;
    }
    return 0;
}//green  d f s?     can not
