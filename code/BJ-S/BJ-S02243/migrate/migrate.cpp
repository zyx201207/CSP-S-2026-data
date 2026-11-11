#include <bits/stdc++.h>
using namespace std;
const int M = 2000006;
long long n,d,c,t,a[M],ans;
long long dis[M],vis[M];
bool inq[M];
vector <int> v[5003];
long long read(){
    char c = getchar();
    long long x = 1,ret = 0;
    while(c < '0' || c > '9'){
        if(c == '-')x = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        ret = ret*10+c-'0';
        c=getchar();
    }
    return ret*x;
}
void bfs(int pos){
    queue <int> q;
    q.push(pos);
    while(q.size()){
        int a = q.front();
        q.pop();
        if(vis[a]==2)ans++;
        for(int i = 0; i < v[a].size(); i++){
            int to = v[a][i];
            if(dis[to]<dis[a]+1)continue;
            if(dis[to]>dis[a]+1)vis[to]=0;
            vis[to]++;
            dis[to]=dis[a]+1;
            if(!inq[to])q.push(to);
            inq[to]=1;
        }
    }

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c = read();
    t = read();
    while(t--){
        ans = 0;
        n = read();d = read();bool b = 1;
        for(int i = 1; i <= n; i++){
            a[i]=read();
            if(i >= 3){
                if(a[i]-a[i-1] != a[2]-a[1])b=0;
            }
        }
        if(n > 5000 || b){
            if(b){
                long long gc = a[2]-a[1];
                long long dist = d/gc;
                if(dist < 2){
                    cout <<0 <<endl;
                    continue;
                }
                if(dist*2-1 <= n)cout << n - (dist*2-1) <<endl;
                else cout << 0 <<endl;
            }
            else{

            }
        }
        else{
            for(int i = 0; i <= n; i++){
                v[i].clear();
            }
            for(int i = 0; i <= n; i++){
                for(int j = i+1; j <= n; j++){
                    if(a[j]-a[i]<=d){
                        v[i].push_back(j);
                        v[j].push_back(i);
                    }
                    else break;
                }
            }
            for(int i = 1; i <= n; i++){
                memset(dis,0x3f,sizeof(dis));
                memset(vis,0,sizeof(vis));
                memset(inq,0,sizeof(inq));
                dis[i]=0;
                bfs(i);
            }
            cout << ans <<endl;
        }
    }
    return 0;
}
