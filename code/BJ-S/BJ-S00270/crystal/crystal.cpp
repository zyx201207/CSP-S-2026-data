#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int n,m;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int val=0;
    int r=1;
    int ans=0;
    for(int l=1;l<=n;l++)
    {
        while(r+1<=n&&val+(a[r+1]-a[r])*(r+1-l)<=m)
        {
            val=val+(a[r+1]-a[r])*(r+1-l);
            r++;

        }
      //  cout<<l<<" "<<r<<endl;
        ans=max(ans,r-l+1);
        val=val-(a[r]-a[l]);
    }
    cout<<ans;
    return 0;
}
