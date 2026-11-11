#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int d[500005];
int f[300005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int cnt = 0;
        for(int j = i;j <= n;j++){
            if(f[a[j]]){
                while(d[cnt] != a[j] && cnt > 0){
                    f[d[cnt]]--;
                    d[cnt--] = 0;

                }
            }else{
                d[++cnt] = a[j];
                f[a[j]]++;
            }
        }
        //for(int j = 1;j <= n;j++){
        //    cout << d[j] << " ";
        //}
        //cout << "\n";
        for(int j = 1;j <= n;j++){
            if(d[j] == 0){
                break;
            }
            ans[d[j]]++;
            d[j] = 0;
        }
        for(int j = 1;j <= n;j++){
            f[j] = 0;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << " ";
    }
    return 0;
}
