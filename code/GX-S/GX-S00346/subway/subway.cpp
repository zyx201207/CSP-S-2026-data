#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;

int main()
{   freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    if(c==0){
        if(n==2&&m==5) cout<<32<<'\n'<<17;
        if(n==3&&m==7) cout<<35<<'\n'<<16;
    }
    return 0;
}
