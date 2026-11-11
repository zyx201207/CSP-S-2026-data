#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k,ans;
bool flag[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ans=a[1];
    for(int j=2;j<=m;j++)
    {
        ans=(ans&a[j]);
    }
    for(int i=m+1;i<=n;i++)
    {
        int p=0;
        for(int j=1;j<i;j++)
        {
            if(flag[j]==1)continue;
            int t=a[i];
            for(int g=1;g<i;g++)
            {
                if(flag[g]==1||g==j)continue;
                t=(t&a[g]);
            }
            if(t>ans)
            {
                p=j;
                ans=t;
            }
        }
        flag[p]=1;
    }
    cout<<ans;
    return 0;
}
