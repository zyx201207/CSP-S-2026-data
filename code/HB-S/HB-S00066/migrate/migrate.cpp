//last :(
#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n,d;
int a[2000005];
int kkk;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>kkk>>t;
    for(int DFEREADD=1;DFEREADD<=t;DFEREADD++)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int dis=a[j]-a[i];
                int mid=0;
                if(dis<=d||dis>2*d)continue;
                for(int k=i+1;k<j;k++)
                    if(a[k]<=a[i]+d&&a[k]>=a[j]-d&&a[k]<=a[j]+d&&a[k]>=a[i]-d)
                        mid++;
                if(mid==2)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
