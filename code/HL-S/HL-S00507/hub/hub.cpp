#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1000;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
            cout<<2<<'\n';
        else
            cout<<1<<'\n';
    }
    return 0;
}
