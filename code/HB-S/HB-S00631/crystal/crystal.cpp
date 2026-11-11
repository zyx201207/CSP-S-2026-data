#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],pr[N],ans=1;
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,pos=i,mid;
        while(l<=r)
        {
            mid=l+r>>1;
            if((i-mid+1)*a[i]-(pr[i]-pr[mid-1])<=m) r=mid-1,pos=mid;
            else l=mid+1;
        }
        //cout<<pos<<' '<<i<<endl;
        ans=max(ans,i-pos+1);
    }
    cout<<ans<<endl;
    return 0;
}
/*
思路
考虑贪心
首先将数组排序并求出前缀和
若最后全部合并成a[i]
那么最优秀的一定是将a[i-1],a[i-2]…………合并成为a[i]，需要操作次数为a[i]-a[i]+a[i]-a[i-1]+……也就是len*a[i]-pr[i]-(pr[i-len]),然后直接二分即可，复杂度nlogn，
计算答案部分没有像有没有更优秀的算法，但nlohn的排序是一定的，所以最终复杂度依然为nlogn
14:50通过了全部样例
注意开long long
csp-s T1 RP++
*/
/*
5 5
1 2 4 8 9
*/
