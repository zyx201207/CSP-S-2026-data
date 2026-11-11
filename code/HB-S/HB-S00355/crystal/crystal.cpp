#include<bits/stdc++.h>
using namespace std;
long long m,a[500010],sum[500010],cha[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //sum[i]=sum[i-1]+a[i];
        //cha[i]=i*a[i]-sum[i-1];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    int r=1,len,ans=-1,now;
    for(int l=1;l<=n&&r<=n;l++)
    {
        len=r-l+1;
        while(1)
        {
            if(a[r+1]*len+sum[l-1]-sum[r]<=m&&r<=n)
            {
                r++;len++;
                ans=max(len,ans);
                //cout<<r<<" "<<len<<" "<<ans<<endl;
            }
            else break;
        }
    }
    cout<<ans;
    return 0;
}
