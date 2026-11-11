#include<bits/stdc++.h>
using namespace std;
int ls[500001],lf[500001],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> ls[i];
    }
    sort(ls+1,ls+n+1);
    int l = 1,r = 1,cvt = 0,ans = 0,cnt = 0;
    while(r < n && l < n){
        if(cvt + (cnt+1) * (ls[r+1] - ls[r]) <= m){
            cvt += (cnt+1) * (ls[r+1] - ls[r]);
            cnt += 1;
            r += 1;
        }
        else{
            cnt -= 1;
            cvt -= (ls[r] - ls[l]);
            l += 1;
        }
        //cout << "cnt:" << cnt << " cvt:" << cvt << " l:" << l << " r:" << r << " ans:" << ans << "\n";
        ans = max(ans,cnt);
    }
    cout << ans+1;
}
