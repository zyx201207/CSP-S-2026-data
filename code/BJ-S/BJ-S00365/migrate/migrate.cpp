#include <iostream>
using namespace std;
int c,t;
int n,d;
int a[2000010];
int tmp,res;
int f(int x,int y){
    int cnt = 0;
    int p = x;
    while(1){
        cnt ++;
        int i = p + 1;
        while(a[i] - a[p] <= d && i <= y){
            i ++;
        }
        if(i > p + 1){
            i --;
        }
        p = i;
        if(p == y){
            break;
        }
    }
    return cnt;
}
void Dfs(int y,int p,int cc){
    if(p == y){
        if(cc == tmp){
            res ++;
        }
        return;
    }
    for(int i = p + 1;a[i] - a[p] <= d && i <= y;i ++){
        Dfs(y,i,cc + 1);
    }
}
int ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t --){
        ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i ++){
            cin >> a[i];
        }
        for(int i = 1;i <= n;i ++){
            for(int j = i + 3;j <= n;j ++){
                tmp = f(i,j);
                res = 0;
                Dfs(j,i,0);
                if(res == 2){
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}