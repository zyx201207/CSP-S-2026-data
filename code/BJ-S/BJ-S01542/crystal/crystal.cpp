#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
ll a[N];
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
    ll j=1;
    ll cnt=0,ans=1;
    for(ll i=2;i<=n;i++){
        cnt+=(a[i]-a[i-1])*(i-j);
        while(cnt>m){
            cnt-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout << ans;
    return 0;
}
