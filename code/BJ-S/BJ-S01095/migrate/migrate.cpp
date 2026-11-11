#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;

const int N = 2e6+9;

int n,C,d,a[N];
bool vis[N];

int dfs(int u,int v){
    queue<pii > q;
    q.push({1,u});
    int dis=0x7fffffff, cnt=0;
    while(!q.empty()){
        pii item=q.front();
        q.pop();
        int x=item.second;
        if(x==v){
            if(item.first<dis){
                dis=item.first;
                cnt=1;
            }else if(item.first==dis){
                ++cnt;
            }
            continue;
        }
        for(int y=x+1;y<=n&&a[y]-a[x]<=d;y++){
            q.push({item.first+1,y});
        }
    }
    return cnt;
}

void solve12(){
    int cnt=0;
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            if(dfs(i,j)==2){
                ++cnt;
            }
        }
    }
    cout<<cnt;
}

void solve(int T) {

    for(int i = 1;i<=n;i++){
        a[i]=0;
        vis[i]=0;
    }
    cin>>n>>d;
    for(int i = 1; i<=n;i++) cin>>a[i];

        solve12();
        return;

}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int T;
    cin>>C>>T;
    while(T--){
        solve(T);cout<<endl;

    }

    return 0;
}
