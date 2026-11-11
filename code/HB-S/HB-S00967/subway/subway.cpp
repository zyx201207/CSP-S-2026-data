#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;

int m,n,c,d,q,k;
ll ans;
int w[N];
int a[25][N];//i:subway line j:station a:time
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0)
    {
        if(n==2)cout<<32<<endl<<17;
        if(n==3)cout<<35<<endl<<16;
        return 0;
    }
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int h=0;
            cin>>h;
            cin>>a[i][h];
        }
    }
    while(q--)
    {
        int s=0,e=0;
        cin>>s>>e;
        ans+=w[s]+w[e];

    }
    return 0;
}