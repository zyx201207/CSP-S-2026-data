#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int sum[N];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i,res=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            int num=sum[i]-sum[mid-1];
            int len=i-mid+1;
            if(len*a[i]-num<=k)
            {
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<endl;
    return 0;
}