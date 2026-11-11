#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N];
long long zhan[N],sum;
long long ans[N];
long long cnt;
long long l=1,r=1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            ans[i]=1;
            zhan[1]=1;
            continue;
        }
        sum+=(a[i]-a[i-1])*(r-l+1);
        if(sum<=m)
        {
            r++;
            zhan[r]=i;
            ans[i]=(r-l+1);
        }
        else
        {
            while(1)
            {
                sum-=(a[i]-a[zhan[l]]),l++;
                if(sum<=m || l>=r) break;
            }
            r++;
            zhan[r]=i;
            ans[i]=(r-l+1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cnt=max(cnt,ans[i]);
    }
    cout<<cnt;
    return 0;
}
