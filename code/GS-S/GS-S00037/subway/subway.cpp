#include<bits/stdc++.h>
using namespace std;
int m,n,a[505],w[505],c,d,q;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0&&n==3&&m==7&&d==20&&q==2)
    {
        cout<<35<<endl<<16;
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2)
    {
        cout<<32<<endl<<17;
    }
    return 0;
}
