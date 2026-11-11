#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e6+5;
ll x[N];

bool check(int u,int v){
    return 0;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("migrate.in","r",stdin);//必须检查！必须检查！必须检查！
    freopen("migrate.out","w",stdout);//必须检查！必须检查！必须检查！
    //输入
    int c,t;
    cin >> c >> t;
    while(t--){
        //初始化
        int n;ll d;
        memset(x,0,sizeof(x));
        //输入
        cin >> n >> d;
        for (int i = 1;i <= n;i++) cin >> x[i];
        ll ans=0;
        for (int u = 1;u <= n;u++){
            for (int v = u+1;v <= n;v++){
                if (check(u,v)) ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
