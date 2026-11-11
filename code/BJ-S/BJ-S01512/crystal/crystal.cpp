#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[100005],k;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,x,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        b[x]++;
        if(b[x]<2)a[++k]=x;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=k;i++)
    {
        long long cnt=b[a[i]],sum=m;
        for(int j=i-1;j>0;j--)
        {
            long long z=b[a[j]]*(i-j);
            if(sum>=z)
            {
                sum-=z;
                cnt+=b[a[j]];
            }
            else
            {
                long long t=sum%(i-j);
                sum-=t;
                cnt+=sum/(i-j);
                break;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
