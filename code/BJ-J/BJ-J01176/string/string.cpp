#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
long long ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,r=n;
    for(;l<=r;)
    {
        if(c[l]!=c[r])
        {
            ans+=min(a[l],a[r]);
        }
        int minn=min(a[r],a[l]);
        a[r]-=minn;
        a[l]-=minn;
        if(a[r]==0)
            r--;
        else
            l++;
    }
    cout<<ans;
    return 0;
}
