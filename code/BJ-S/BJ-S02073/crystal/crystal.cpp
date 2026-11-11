#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum,avg,b[500005],num[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum-=a[n];
    sort(a+1,a+n+1);
    avg=sum/n;
    for(int i = 1;i<=m;i++)
    {
        int x=1e9,p=0;
        for(int j = 1;j<=n;j++)
        {
            b[j]=avg-a[j];
            if(b[j]<0) b[j]=1e9+1;
            if(x>b[j])
            {
                x=b[j];
                p=j;
            }
        }
        a[p]++;
    }
    /*for(int i = 1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;*/
    for(int i = 1;i<=n;i++)
    {
        num[a[i]]++;
    }
    int ans=0;
    for(int i = 1;i<=n;i++)
    {
        ans=max(ans,num[i]);
    }
    cout<<ans;
    return 0;
}
