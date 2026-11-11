#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200011];
bool ca[200011];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)ca[i]=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int s=30;s>=0;s--)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)if(ca[i]&&(a[i]&(1<<s)))cnt++;
        if(cnt>=m)
        {
            ans+=(1<<s);
            for(int i=1;i<=n;i++)if((a[i]&(1<<s))==0)ca[i]=0;
        }
    }
    cout<<ans;
    return 0;
}
