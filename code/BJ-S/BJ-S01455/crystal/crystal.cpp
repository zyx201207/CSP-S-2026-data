#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,ans=-1,ch[500005],sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        ch[i]=a[i]-a[i-1];
    }
    for(int i=2;i<=n;i++)
    {
        if(n-i+1==ans)
            break;
        sum=0;
        for(int j=i;j<=n;j++)
        {
            sum+=(j-i+1)*ch[j];
            if(sum>m)
            {
                if(j-i+1>ans)
                {
                    ans=j-i+1;
                    break;
                }
            }
            else if(sum==m&&ch[j+1]>0)
            {
                if(j-i+2>ans)
                {
                    ans=j-i+2;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
