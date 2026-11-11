#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,d,ans;
const int MOD = 1e9+7;
int a[2000005],cnt[2000005],dis[2000005];
vector<int> v[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        ans = 0;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            v[i].clear();
        }
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        if(c==11 || c==12){
            if(d<2*(a[2]-a[1])){
                cout << 0 << endl;
                continue;
            }
            cout << max(0ll,n-3-2*(d/(a[2]-a[1])-2)) << endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
                else{
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            queue<int> que;
            for(int j=1;j<=n;j++){
                cnt[j] = 0;
                dis[j] = 9e18;
            }
            que.push(i);
            dis[i] = 0;
            cnt[i] = 1;
            while(!que.empty()){
                int x = que.front();
                que.pop();
                for(auto y:v[x]){
                    if(dis[y]<dis[x]+1){
                        continue;
                    }
                    if(dis[y]>dis[x]+1){
                        dis[y] = dis[x]+1;
                        cnt[y] = cnt[x];
                        que.push(y);
                    }
                    else{
                        cnt[y] = (cnt[x]+cnt[y])%MOD;
                    }
                }
            }
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
//                    cout << i << " " << j << " " << dis[j] << " " << cnt[j] << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

