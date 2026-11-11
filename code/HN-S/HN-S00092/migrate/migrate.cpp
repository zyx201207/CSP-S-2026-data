#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int L[N] , R[N] , n , dis[N] , d , cntfront[N] , cntlast[N];
void solve(){
    cin >> n >> d;
    for(int i=1;i<=n;i++)cin >> dis[i] , L[i] = R[i] = 0 , cntfront[i] = 0 , cntlast[i] = 0;
    for(int l=1,r=1;l<=n;l++){
        while(r<n&&dis[r+1]-dis[l]<=d)r++;
        R[l] = r;
    }
    for(int l=n,r=n;r>=1;r--){
        while(l>1&&dis[r]-dis[l-1]<=d)l--;
        L[r] = l;
    }
    for(int i=1;i<=n;i++){
        cntfront[i]++;
        if(L[R[i]]==i)cntfront[R[i]] += cntfront[i];
        else cntfront[R[i]]++;
    }
    for(int i=n;i>=1;i--){
        cntlast[i]++;
        if(R[L[i]]==i)cntlast[L[i]] += cntlast[i];
        else cntlast[L[i]]++;
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(R[i]-i<2)continue;
        int r1 = R[R[i]] , r2 = R[R[i]-1] , r3 = R[R[i]-2];
        if(r3==r2)continue;
        if(r1!=r2)cnt += cntfront[i] * (r2 - r3);
        else cnt += cntfront[i] * (cntlast[r2] + r2 - r3 - 1);
    }
    cout << cnt << "\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int tp , T;cin >> tp >> T;
    while(T--)solve();
    return 0;
}