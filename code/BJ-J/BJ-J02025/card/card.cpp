#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
struct csp
{
    int r,p;
}b[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(b[a[i]].r==0)
        {
            b[a[i]].r=i;
        }
        b[a[i]].p=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(b[i].p==n)
        {
            cout<<n<<" ";
        }
        else
        {
            cout<<b[i].p-b[i].r-1<<" ";
        }
    }
    return 0;
}
