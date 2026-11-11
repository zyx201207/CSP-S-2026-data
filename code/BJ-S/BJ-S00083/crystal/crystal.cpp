#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
ll n,m,a[N],ans=0;
bool check(ll mid){
    ll cnt = 0;
    for (int i = 1;i <= n;i++){
        if (a[i]>=mid)break;
        cnt+=mid-a[i];
        if (cnt>m)return 0;
    }
    return 1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll l=1,r=n;
    while (l<=r){
        ll mid = (l+r)/2;
        if (check(mid)){
            ans=mid;
            l=mid+1;
        }else {
            r=mid-1;
        }
    }
    ll sum=0;
    for (int i = 1;i <= n;i++){
        if (a[i]>ans)break;
        sum++;
    }
    cout << sum <<"\n";
    return 0;
}
