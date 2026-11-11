#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5e5,MAXM=3e5;
int a[MAXN+5],lp[MAXM+5],cnt[MAXM+5],d[MAXN+5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        memset(lp,0,sizeof(lp));
        memset(d,0,sizeof(d));
        for(int j=i;j<=n;++j)
        {
            if(lp[a[j]]!=0)
            {
                if(d[lp[a[j]]]==0)
                {
                    for(int k=lp[a[j]];k<j;++k)
                    {
                        ++d[k];
                    }
                    lp[a[j]]=j;
                }
                else
                {
                    lp[a[j]]=j;
                }
            }
            else
            {
                lp[a[j]]=j;
            }
        }
        for(int j=i;j<=n;++j)
        {
            if(d[j]==0)
            {
                ++cnt[a[j]];
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        cout<<cnt[i]<<' ';
    }
    return 0;
}
