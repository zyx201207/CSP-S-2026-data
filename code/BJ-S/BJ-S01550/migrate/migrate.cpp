#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n,d;
int sum,len;
int a[5005];
int cnt[5005];
void dfs(int s,int t,int step){
    if(s == t){
        if(step == (len-1)/d+1){
            sum++;
        }
        return ;
    }
    for(int i = s+1; i <= t; i++){
        if(a[i]-a[s] > d){
            continue;
        }
        dfs(i,t,step+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t ;
    while(t--){
        cin >> n >> d ;
        for(int i = 1; i <= n; i++){
            cin >> a[i] ;
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                sum = 0;
                len = j-i+1;
                dfs(i,j,0);
                if(sum == 2){
                    ans++;
                }
            }
        }
        cout << ans << "\n" ;
    }
    return 0;
}
