#include<bits/stdc++.h>
using namespace std;
const long long M=5*1e5+20;
long long a[M],sum[M];
bool cmp(long long x,long long y)
{
    return x<y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    sum[1]=0;
    for(long long i=2;i<=n;i++)
    {
        sum[i]=(a[i]-a[i-1])*(i-1)+sum[i-1];
        //cout<<sum[i]<<" "<<a[i]-a[i-1]<<" "<<a[i]<<" "<<a[i-1]<<endl;
        if(sum[i]>m)
        {
            ans=i-1;
            break;
        }
    }
    if(n>=10000*2)
    {
        cout<<ans;
        return 0;
    }
    for(long long i=2;i<=n;i++)
    {
        long long x=sum[i],k=1;
        while(x<=m)
        {
            if(k+i>n)
            {
                k=1;
                break;
            }
            x=(sum[i+k]-sum[i+k-1])/(i+k-1)+x;
            k++;
        }
        k--;
        ans=max(ans,k);
    }
    cout<<ans;
    return 0;
}

