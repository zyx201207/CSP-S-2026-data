#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n+5],t[n];
    map<int,int> mp;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        mp[i]++;
    }
    sort(a+1,a+n+1);
    int mx = 0,mi;
    for(auto [i,j]:mp){
        if(j>=mx){
            mx = j;
            mi = i;
        }
    }

    int cha[mi+5];
    for(int i = 1;i<=mi;i++){
        cha[i] = abs(mx-a[i]);
    }
    sort(cha+1,cha+mi+1);
    int cnt = 0,ans = 0;
    for(int i = 1;i<=mi;i++){
        if(cnt+cha[i]<=m){
            cnt+=cha[i];
            ans++;
        }
    }
    cout << mx << mi;
    return 0;
}
