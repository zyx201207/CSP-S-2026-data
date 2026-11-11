
#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200005];
int ans;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n-m;i++)
    {
        int sum=a[i-1];
        for(int j=i+1;j<=i+m;j++)
        {
            sum+=sum&a[j];
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
