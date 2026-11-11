#include <bits/stdc++.h>
using namespace std;

long long x[5005];
int f[5005];
int cnt[5005];
vector<int> edges[5005];
void solve(){
    int n;
    long long d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            if(x[j]-x[i]<=d){
                edges[i].push_back(j);
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[j]=0;
            cnt[j]=0;
        }
        queue<int> q;
        q.push(i);
        while(!q.empty()) {
            int x=q.front();
            q.pop();
            for(auto y:edges[x]){
                if(f[y]==0){
                    f[y]=f[x]+1;
                    cnt[y]=1;
                    q.push(y);
                }else{
                    if(f[y]==f[x]+1){
                        cnt[y]++;
                        q.push(y);
                    }
                }

            }
        }
        for(int j=1;j<=n;j++) {
            //cout<<f[j]<<" ";
            if(cnt[j]==2) ans++;
        }
    }
    cout<<ans<<"\n";

    for(int i=1;i<=n;i++){
        edges[i].clear();
    }

}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        solve();
    }


    return 0;
}
