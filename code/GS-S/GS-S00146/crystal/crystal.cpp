#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5e5+5;
int n;
ll m;
ll a[N],pre[N];

bool check(ll pos1,ll pos2){
    ll sum1 = pre[pos2]-pre[pos1-1];
    ll sum2 = a[pos2]*(pos2-pos1+1);
    return sum2-sum1 <= m;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("crystal.in","r",stdin);//必须检查！必须检查！必须检查！
    freopen("crystal.out","w",stdout);//必须检查！必须检查！必须检查！
    //输入
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    //处理
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i++) pre[i] = pre[i-1]+a[i];
    ll ans = -1;
    for (ll pos2 = 1;pos2 <= n;pos2++){
        //已排序，二分查找寻找最左端点
        ll l = 1,r = pos2,pos1=-1;
        while(l <= r){
            ll mid = (l+r)/2;
            if (check(mid,pos2)){
                pos1 = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        ans = max(ans,pos2-pos1+1);
    }
    cout << ans;
    return 0;
}
