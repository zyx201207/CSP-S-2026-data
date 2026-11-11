#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],lst[300005],cnt=0,ans[300005],q[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=300003;i++)
    {
        lst[i]=-1;
        ans[i]=0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cnt=0;
        for(int j=i;j<=n;j++)
        {
            if(lst[a[j]]==-1)
            {
                cnt++;
                q[cnt]=a[j];
                lst[a[j]]=cnt;
            }
            else
            {
                for(int k=lst[a[j]]+1;k<=cnt;k++)
                {
                    lst[q[k]]=-1;
                    q[k]=0;
                }
                cnt=lst[a[j]];
            }
        }
        for(int j=1;j<=cnt;j++) ans[q[j]]++;
        for(int i=1;i<=m;i++) lst[i]=-1;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
