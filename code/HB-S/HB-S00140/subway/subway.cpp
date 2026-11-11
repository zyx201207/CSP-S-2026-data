#include<bits/stdc++.h>
using namespace std;
struct node{
int a,t;
}cnt[550][50050];
bool cmp(node x,node y){
    return x.a < y.a;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int c,n,m,d,q,tim[50050],k[550];
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++) cin >> tim[i];
    for(int i = 1;i <= n;i ++){
        cin >> k[i];
        for(int j = i;j <= 2 * k[i];j ++) cin >> cnt[i][j].a >> cnt[i][j].t;
    }
    while(q --){
        int be,en;
        int ans = 0;
        cin >> be >> en;
        ans += tim[be] + tim[en];
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= k[i];j ++){
                if(cnt[i][j].a == be) ans += cnt[i][j].t;
                if(cnt[i][j].a == en) ans += cnt[i][j].t;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
