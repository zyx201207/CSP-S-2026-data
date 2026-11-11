#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll a[maxn];
ll t[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        t[i-1]=a[i]-a[i-1];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
        ll k=t[i]*i;
        if(m-k>=0){
            m-=k;
            ans++;
        }
        else break;
    }
    cout << ans;
    return 0;
}
