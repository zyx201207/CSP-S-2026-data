#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[2000010],dis[2000010],cnt[2000010];
ll n,d;
void bfs(int s){
    queue<int> q;
    q.push(s);
    dis[s]=0,cnt[s]++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            int v=i;
            if(abs(x[u]-x[v])<=d){
                if(cnt[v]==0){
                    dis[v]=dis[u]+1;
                    cnt[v]++;
                    q.push(v);
                }
                else{
                    if(dis[u]==dis[v]-1){
                        cnt[v]++;
                    }
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)   cin>>x[i];
        sort(x+1,x+n+1);
        int da=x[2]-x[1];
        if(c==11||c==12){
            ll ans=d/da+1;
            cout<<n-ans<<endl;
        }
        else if(c==13||c==14){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(x[i]-x[1]<=d&&x[n]-x[i]<=d)  cnt++;
            }
            if(cnt==1)  cout<<0;
            else    cout<<n*(n+1)/2-1;
        }
        else{
            ll ans=0;
            for(int i=1;i<=n;i++){
                memset(cnt,0,sizeof cnt);
                bfs(i);
                for(int j=1;j<=n;j++){
                    if(i==j)    continue;
                    if(cnt[j]==2)   ans++;
                }
            }
            cout<<ans/2<<endl;
        }
    }
    return 0;
}
