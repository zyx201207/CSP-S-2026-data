#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int arr[N];
int n,m;
int xmax=0;
int sum[N];
int gongbi;
int ef(int x)
{
    int ans=0;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int tou=mid%gongbi;
        if((mid+tou)*((mid-tou)/gongbi+1)/2<=x)
        {
            ans=(mid-tou)/gongbi+1;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return ans;
}
void tp1()
{
    bool flag=0;
    gongbi=arr[2]-arr[1];
    for(int i=2;i<=n;i++)
    {
        if(arr[i]-arr[i-1]!=gongbi)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        return;
    cout<<ef(m);
    exit(0);
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    tp1();

    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+arr[i];
    }
    //cout<<'\n';
    int xmax=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int ans=sum[j]-sum[i-1];
            ans+=m;
            //if(i==1)
            //    cout<<ans<<" ";
            int gong=ans/arr[j];
            //if(i==1)
            //    cout<<gong<<" ";
            if(llabs(gong)>=j-i+1ll)
            {
                //cout<<i<<" "<<j<<'\n';
                //cout<<"YES\n";
                xmax=max(xmax,j-i+1ll);
                //cout<<j-i+1ll<<"            zb\n";
            }
        }
    }
    cout<<xmax;
    return 0;
}
