#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],c[M],ans[M],b[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int j=i;j<=n;j++)
        {
            b[a[j]]++;
            if(c[a[j]]==0) c[a[j]]=j;
            else
            {
                for(int k=c[a[j]];k<j;k++)
                {
                    b[a[k]]=0;
                }
                b[a[j]]=1;
                c[a[j]]=j;
            }
        }
        for(int w=1;w<=m;w++)
        {
            ans[w]+=b[w];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
