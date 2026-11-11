#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,d;
int a[N],pre[N],nxt[N],dp1[N];
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i],dp1[i]=1;
        for(int i=1;i<=n;i++)
        {
            int l=1,r=i,mid,ans=-1;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(a[i]-a[mid]<=d)
                {
                    ans=mid;
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            pre[i]=ans;
        }
        for(int i=1;i<=n;i++)
        {
            if(pre[i]<i&&pre[i+1]!=pre[i])
                dp1[i]+=dp1[pre[i]];
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(i-pre[i]>=2)
            {
                int j=pre[i]+1;
                if(j-pre[j]>=2)
                {
                    for(int r=pre[j];r<pre[j+1];r++)
                    {
                        if(pre[j-1]>pre[r]&&pre[j-1]<r)
                            cnt++;
                        else
                            cnt+=dp1[r];
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
}