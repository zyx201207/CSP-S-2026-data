#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005],ans;
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    ans=a[1];
    for(int i=2;i<=m;i++)
        ans&=a[i];
    int l=m+1;
    if(a[1]%a[2]==0) l=m+1;
    else l=m;
    while(ans==0)
    {
        ans=a[++l];
        for(int i=l;i<=m;i++)
            ans&=a[i];
    }
    cout<<ans<<"\n";
    return 0;
}
