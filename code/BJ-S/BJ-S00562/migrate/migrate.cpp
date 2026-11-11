#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    while(t--){
        int n,d,x[2000005],step[2000005],cnt[30005][30005],ans=0;
        vector<int>g[2000005];
        queue<int>q;
        while(!q.empty()){
            q.pop();
        }
        for(int i=1;i<=2000000;i++){
            g[i].clear();
        }
        memset(step,-1,sizeof(step));
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    g[i].push_back(j);
                }
            }
        }
        q.push(1);
        step[1]=0;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int i=0;i<g[now].size();i++){
                q.push(g[now][i]);
                step[g[now][i]]=step[now]+1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cnt[i][j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
