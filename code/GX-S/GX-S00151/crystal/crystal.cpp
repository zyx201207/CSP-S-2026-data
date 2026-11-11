///回家我要耍起！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll n,m;
ll a[N];
bool check(ll k){
    //为了验证a[k]为中间值时能合成多少水晶
    ll sum=0;
    for(ll i=1;i<=k;i++){//右边无需考虑
        sum+=a[k]-a[i];//花销
    }
    return sum<=m;//一定要不超过m
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    ll l=1,r=n,ans=0;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
/*

5 5
1 2 4 8 9

真错就给了，但是这次能不能给我一个惊喜啊，如果考了s1我就退休111

5 8
2 7 9 2 9

排序后：2 2 7 9 9
选中7 可修改：2 2
2+5=7，2+5=7
5+5>8
所以只有两个
*/
