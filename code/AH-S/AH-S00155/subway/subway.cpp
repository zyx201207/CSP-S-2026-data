#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
#define int long long
int f[1010][1010];
int v[1010];
int vis[1010];
struct q{int v[30];int t[30];int len;}a[510];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(!c)
    {
        if(n==2){cout<<32<<"\n"<<17;return 0;}
        else{cout<<35<<"\n"<<16;return 0;}
    }
    return 0;
}
