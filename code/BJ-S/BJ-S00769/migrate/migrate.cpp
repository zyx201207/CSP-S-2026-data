#include<bits/stdc++.h>
using namespace std;
const long long INF=1e16;
long long c,T,n,d,ans;
long long a[2000005],dis[2000005],cnt[2000005],inq[2000005];
vector<int> e[2000005];
void bfs(int x){
    dis[x]=0;
    queue<int> q;
    q.push(x);
    cnt[x]=1;
    inq[x]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int i=u+1;i<=n;i++){
            if(a[i]-a[u]>d){
                break;
            }
            if(dis[i]>dis[u]+1){
                dis[i]=dis[u]+1;
                cnt[i]=cnt[u];
                if(!inq[i]){
                     q.push(i);
                     inq[i]=1;
                }

            }else if(dis[i]==dis[u]+1){
                cnt[i]+=cnt[u];
                if(!inq[i]){
                     q.push(i);
                     inq[i]=1;
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[j]=INF;
                cnt[i]=0;
            }
            bfs(i);
            for(int j=1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }

            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
