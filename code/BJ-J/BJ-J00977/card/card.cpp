#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=3e5+10;
int ans[M],a[N],n,m;
int tag[M];
int q[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
   for(int i=1;i<=n;i++)
    {
        int h=0;
       for(int j=1;j<=m;j++)
        {
            tag[j]=0;
            q[i]=0;
        }
        for(int j=i;j<=n;j++)
        {
            if(tag[a[j]]==0)
            {
                h++;
                q[h]=a[j];
                tag[a[j]]=h;
            }
            else
            {
               for(int k=tag[a[j]]+1;k<=h;k++)
                {
                   tag[q[k]]=0;
                }
                h=tag[a[j]];
            }
        }
        for(int j=1;j<=h;j++)
        {
            ans[q[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
