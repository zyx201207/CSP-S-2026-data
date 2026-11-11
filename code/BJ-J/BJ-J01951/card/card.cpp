#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans[300005],bs[500005];
ll b[300005];
bool tb[300005];
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
        memset(bs,0,sizeof(bs));
        memset(b,0,sizeof(b));
        memset(tb,false,sizeof(tb));
        ll zb=0;
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]==0)
            {
                b[a[j]]=zb+1;
                bs[++zb]=a[j];
            }
            else
            {
                for(int k=b[a[j]]+1;k<=zb;k++)
                {
                    b[bs[k]]=0;
                    bs[k]=0;
                }
                zb=b[a[j]];
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]!=0)
            {
                tb[a[j]]=true;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(tb[i])
            {
                ans[i]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
