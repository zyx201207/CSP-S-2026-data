#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,j=1,sum=0;i<=n;i++,sum-=(a[j]-a[i]))
    {
        while(sum<=m)
        {
            if(j-i+1>ans)
                ans=j-i+1;
            j++;
            if(j==n+1)
                break;
            sum+=((a[j]-a[j-1])*(j-i));
        }
        if(j==n+1)
            break;
    }
    cout<<ans;
    return 0;
}
