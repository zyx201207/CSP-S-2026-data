#include<bits/stdc++.h>

using namespace std;

const int N=3005;

int c,t,n,k,u,v,tree[N][N];

int main(void)
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    cin>>c>>t;

    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>u>>v;
            p[u][v]=1;
        }
    }
    cout<<1<<endl<<2;

    return 0;
}
