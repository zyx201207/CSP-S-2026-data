#include<bits/stdc++.h>
using namespace std;
int cnt[2000006],ans;//every island's quantity of shortcuts
int n;//quantity of islands
int d;//length of flight
int c,q;//number of test and quantity of questions
long long islands[2000006];//every island's situation=>shortcut length
vector<int> g[2000006];//available paths between islands
bool vis[2000006];//whether we have visited islands
void bfs(int a){
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int u:g[cur]){
            if(vis[u]){
                if(islands[cur]+1==islands[u]){
                    cnt[u]++;
                    if(cnt[u]==2) ans++;
                    if(cnt[u]==3) ans--;
                }
                continue;
            }
            q.push(u);
            islands[u]=islands[cur]+1;
            cnt[u]++;
        }
    }
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> c >> q;
    while(q--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> islands[i];
            for(int j=i-1;j>=1;j--){
                if(islands[i]-islands[j]>d) break;
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            memset(islands,0x7f7f7f7f7f7f7f7f,sizeof islands);
            bfs(i);
        }
        cout << ans  << endl;
    }
    return 0;
}






