#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s,ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(long long l=1,r=1;r<=n;r++)
    {
        s+=(r-l)*(a[r]-a[r-1]);
        while(s>m) s-=a[r]-a[l],l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
