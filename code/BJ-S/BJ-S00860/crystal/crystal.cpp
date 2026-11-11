#include<bits/stdc++.h>
using namespace std;
const int N=5e5+507;
const int M=5e3+7;
const int INF=0x3f3f3f3f;
typedef long long ll;

ll T=1,n,m;

ll a[N],dp[N],ans=-1;

int mian()
{
    /*init*/
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    dp[1]=0;
    for(ll i=2,j=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+(i-j)*(a[i]-a[i-1]);
        while(dp[i]>m)
        {
            dp[i]-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans<<"\n";
    //
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //cin>>T;
    while(T--)
    {
        mian();
    }
    return 0;
}

/*
======CHECK LIST========

file i/o [DONE]
long long [DONE]
adjust array ranges [DONE]
calculate time [O(nlogn+2n)]
calculate space [O(n)]
initialization [NONE NEEDED]
remove extra outputs [NONE]
check all warnings (Wall) [DONE]

*/
