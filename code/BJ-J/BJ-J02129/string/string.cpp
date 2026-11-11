#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200001],l,r;
char c[200001];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    l=1;
    r=n;
    while(l<r)
    {
        int t=min(a[l],a[r]);
        if(c[l]!=c[r]) ans+=t;
        a[l]-=t;
        a[r]-=t;
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}