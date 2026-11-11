#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,i,k,w[500005],x,y,p,l,l2[505],t[505],a[500005],r;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for (i=1;i<=m;i++)
    {
         cin>>w[i];
    }
    for (i=1;i<=n;i++)
    {
        cin>>k;
        l+=k;
        l2[i]=k;
        for (int j=l+1;j<=2*k;j++)
        {
            cin>>a[j]>>t[j];
        }
    }

    for (i=1;i<=q;i++)
    {
        cin>>x>>y;
        p+=w[x];
        int e=1;
        while (a[r]!=y&&r<=n)
        {
                r++;
                p+=t[r];
        }
        p+=w[y];
        cout<<p<<endl;
    }
    return 0;
}
