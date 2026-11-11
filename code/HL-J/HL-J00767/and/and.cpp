#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=LONG_LONG_MAX,tot,cnt;
bool b[200005];
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=32;i>=0;i--)
    {
        cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(!b[j])cnt+=((a[j]>>i)&1);
        }
        if(cnt<m)continue;
        if(cnt==m)
        {
            for(int j=1;j<=n;j++)
            {
                if(((a[j]>>i)&1)==1&&b[j]==0)ans&=a[j];
            }
            cout<<ans;
            return 0;
        }
        for(int j=1;j<=n;j++)
        {
            if(((a[j]>>i)&1)==0)b[j]=1;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n&&tot<m;i++)
    {
        if(!b[i])
        {
            ans&=a[i];
            cout<<a[i]<<' ';
            tot++;
        }
    }
    cout<<ans;




    return 0;
}
