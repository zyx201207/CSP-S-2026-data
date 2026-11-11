#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
long long ans;
long long w[500005];
struct station{
    long long a,t;
};
vector<station> a[505];
void dfs(int x,long long cnt){
    if(x==y){
        ans=max(ans,cnt+w[y]);
        return;
    }
    for(int i=1;i<=n;i++){
        bool f=0;
        for(auto tmp:a[i]){
            if(tmp.a==x){
                f=1;
                break;
            }
        }
        if(f){
            for(auto tmp:a[i]){
                if(tmp.a!=x) dfs(tmp.a,cnt+tmp.t);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> x >> y;
            a[i].push_back({x,y});
        }
    }
    while(q--){
        cin >> x >> y;
        dfs(x,w[x]);
        cout << ans << '\n';
    }
    return 0;
}
