#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,a[1000010],dis[5010][5010],cnt,ans;
void dfs(int step,int x,int e,int lim){
    if(step > lim+1){
        if(x == e){
            cnt++;
        }
        return;
    }
    for(int i = x;i <= e;i++){
        if(a[i]- a[x] > d){
            break;
        }
        dfs(step+1,i,e,lim);
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >>a[i];
        }
        for(int i = 1;i <= n;i++){
            for(int k = i;k <= n;k++){
                int pos = i;
                for(int j = i;j <= k;j++){
                    if(a[j]-a[pos] > d){
                        j--;
                        pos = j;
                        //cout << pos << endl;
                        dis[i][k]++;
                    }
                }
            }

        }
        //cout << dis[1][4];
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                cnt = 0;
                int lim = dis[i][j];
                dfs(1,i,j,lim);
                if(cnt == 2){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
