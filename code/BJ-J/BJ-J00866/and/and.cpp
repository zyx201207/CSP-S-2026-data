#include<iostream>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,m,a[N + 1],flag[N + 1];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i],flag[i] = true;
    int ans = 0;
    for(int i = 30;i >= 0;i--){
        int cnt = 0;
        for(int j = 1;j <= n;j++)
            if(flag[j] && (a[j] & (1 << i)))
                cnt++;
        if(cnt < m) continue;
        for(int j = 1;j <= n;j++)
            if((a[j] & (1 << i)) == 0)
                flag[j] = false;
        ans += (1 << i);
    }
    cout<<ans<<"\n";
}
