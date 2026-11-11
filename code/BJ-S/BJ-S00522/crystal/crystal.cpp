#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,ans;
long long m;
long long a[maxn];
long long s[maxn];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+(a[n]-a[i]);
    //for(int i=1;i<=n;i++)
    //    cout<<s[i]<<" ";
    //cout<<"\n";
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i;
        while(l<r)
        {
            int mid=(l+r)/2;
            long long x=s[i]-s[mid-1]-1ll*(i-mid+1)*(a[n]-a[i]);
            //cout<<mid<<" "<<i<<" "<<x<<"\n";
            if(x<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
        //cout<<l<<" "<<i<<"\n";
    }
    cout<<ans;
    return 0;
}

