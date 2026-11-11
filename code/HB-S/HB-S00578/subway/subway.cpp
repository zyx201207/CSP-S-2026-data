#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,p;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=0;i<p;i++){
        cout<<c+n+m+d<<'\n';
    }

    return 0;
}
