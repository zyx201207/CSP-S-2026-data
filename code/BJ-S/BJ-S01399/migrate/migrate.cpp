#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int cnt[2000006];
int x[2000006],plan[200006],tr[10000007];

int lb(int a){
    return a&(-a);
}
void pl(int a,int k){
    while(a <= n){
        tr[a] += k;
        a += lb(a);
    }
}
int ask(int a){
    int res = 0;
    while(a > 0){
        res += tr[a];
        a -= lb(a);
    }
    return res;
}

void solve(){
    cin>>n>>d;
    memset(tr,0,sizeof(tr));
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int l = max(0,x[i]-d),r = min(x[n],x[i+d]);
        int posl = (lower_bound(x+1,x+n+1,l)-x);
        int posr;
        if(lower_bound(x+1,x+n+1,r) != x+n+1){
            posr = (lower_bound(x+1,x+n+1,r)-x);
        } else {
            posr = n;
        }
        int sum = 0;
        for(int i=posl;i<=posr;i++){
            sum += ask(i) - ask(i-1);
            if(ask(i) - ask(i-1) == 2){
                ans++;
            } 
        }
        sum = max(1,sum);
        pl(i+1,sum);
        pl(posr+1,-sum);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        solve();
    }
}