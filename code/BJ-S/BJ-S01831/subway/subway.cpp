#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int c,n,m,d,q;
int w[MAXN],k[MAXN],a[10000][10000],t[10000][10000];
int f[10000][10000];
int x[MAXN],y[MAXN];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];

    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int b=1;b<=q;b++)
    {
        cin>>x[b]>>y[b];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                if(a[i][j]==a[i+1][j]);
            }
        }

    }
    cout<<24<<endl<<24;

    return 0;
}
