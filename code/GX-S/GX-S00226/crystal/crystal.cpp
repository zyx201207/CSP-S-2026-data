#include<bits/stdc++.h>
using namespace std;
int n,m,ans = 0;
long long a[500005],pref[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++){
        pref[i]=pref[i-1]+(a[i]-a[i-1])*(i-1);
    }
    ans = lower_bound(pref+1,pref+n+1,m+1)-pref-1;
    cout<<ans;
    return 0;
}
