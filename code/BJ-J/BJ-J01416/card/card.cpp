#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+8;
const int MAXM=3e5+8;
int p[MAXM],a[MAXN],b[MAXN],ans[MAXM];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(p,0,sizeof(p));
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++)
        {
            b[j]=a[j];
            if(p[b[j]])
            {
                for(int k=p[b[j]];k<j;k++)
                {
                    p[b[k]]=0;
                    b[k]=0;
                }
            }
            p[b[j]]=j;
        }
        for(int j=i;j<=n;j++)
        {
            if(b[j])ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
}