#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],ij=1,ans,k[500005];
struct csp
{
    int ak,rp;
}t[500005];
struct noip
{
    int st,en;
}pl[500005];
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
            cin>>t[ij].ak>>t[ij].rp;
            ij++;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>pl[i].st>>pl[i].en;
    }
    for(int i=1;i<=q;i++)
    {
        ans=0;
        ans=w[pl[i].st]+w[pl[i].en];
        for(int j=1;j<=n;j++)
        {
            int pd=0;
            for(int kkk=1;kkk<=k[i];j++)
            {
                if(t[ij].ak==pl[i].st)
                {
                    pd++;
                }
                if(t[ij].ak==pl[i].en)
                {
                    pd++;
                }
            }
            if(pd==2&&ans==w[pl[i].st]+w[pl[i].en])
            {
                cout<<ans;
                break;
            }
        }
    }
    return 0;
}
