#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> s[i];
    }
    sort(s + 1,s + 1 + n);
    int l = 1,cnt = 0,ans = 1;
    for(int i = 2;i <= n;i++){
        cnt += (i - l) * (s[i] - s[i - 1]);
        while(cnt > m && l < i){
            cnt -= s[i] - s[l];
            l++;
        }
        ans = max(ans,i - l + 1);
    }
    cout << ans;
    return 0;
}
