#include <bits/stdc++.h>
using namespace std;
struct edge{
    int u,v;
};
edge a[500005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k,ans;
    cin >> c >> t;
    while(t--){
        ans=0;
        cin >> n >> k;
        for(int i = 1;i <= n-1;i++) cin >> a[i].u >> a[i].v;
        while(k--){
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
