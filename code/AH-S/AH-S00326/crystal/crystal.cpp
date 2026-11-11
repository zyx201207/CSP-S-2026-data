#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5*1e5+5;
int n,m;
int a[N];
vector<int> v;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)
        a[i]=v[i-1]-v[i-2];
    a[0]=a[1]=0;
    int l=1,r=1,sum=0,ans=0;
    while(r<=n)
    {
        sum+=(a[r+1])*(r-l+1),r++;
        if(sum>m)
            while(sum>m) l++,sum-=(a[r]-a[l-1]);
        ans=max(ans,r-l+1);
    }
    cout<<ans<<"\n";
    //Oct31==Dec25?
    return 0;
}