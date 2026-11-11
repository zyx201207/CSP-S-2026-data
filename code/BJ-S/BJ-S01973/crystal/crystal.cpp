#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=1;
int a[N],s[N];
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++) s[i]=s[i-1]+a[i];
    for(int i = 2; i <= n; i++){
        int l=1,r=i-1;
        while(l<=r){
            int mid=(l+r)/2;
            int sum=(i-mid)*a[i];
            sum-=(s[i-1]-s[mid-1]);
            if(sum<=m) r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
    /*
注意到，我们对于任意一个水晶i，在升序排序后，对于任意j>i的水晶，都有aj>ai,也就是说，操作对i后的无效;
可以想到，对于水晶i，1-i-1的每一号水晶，都会严格的小于a[i]的值
因此，我们可以想到去枚举每一个水晶，在他的左边优先填补差较小的元素，直到累加值>m
但是，注意到该算法的时间复杂度是O(n^2)，我们对于N=5e5的情况下必然会超时
因此可以想到优化枚举截至的第二层循环
设sum[i]为前缀和数组，假设水晶j的值为a[j]，其中j<i
那么，我们在j~i-1中，每一个的代价都是summary=a[i]-a[i-1]+…………+a[i]-a[j]，其中一共有i-j个元素
那么我们可以将该式写成(i-j)a[i]-(a[i-1]+a[i-2]+………………+a[j])
即summary=a[i](i-j)-(sum[i-1]-sum[j-1])，带入阳历均可证明其正确性;
那么这道题就很好做了
我们利用二分的思想，对于a[mid]-a[i]的代价，若能够使得summary<=m，那么可以说明我们可以继续提升，那么应该使得mid向左移动，即r=mid-1
同样的，summary>m,那么我们需要让l=mid+1；
最后的长度就是i-l+1，ans打擂台即可；
哦对了记得开长长，因为a[i]能达到滚木的1e12量级
附上代码
*/
}
