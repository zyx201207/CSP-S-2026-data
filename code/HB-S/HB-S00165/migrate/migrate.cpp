/*
CSP-S2 2026
Question.C
Usage Time: 210 min
Expectation Score: 8 points
*/
#include<bits/stdc++.h>
using namespace std;
int c,t;
const unsigned long long inf=2e18+10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        unsigned long long n,d;
        vector<unsigned long long> pos,dis;
        cin>>n>>d;
        pos.resize(n+10);
        dis.resize(n+10);
        for(int i=1;i<=n;i++){
            cin>>pos[i];
        }
        queue<int> q;
        int ans=0;
        for(int j=1;j<=n;j++) dis[j]=inf;
        vector<int> cnt;
        cnt.resize(n+10);
        dis[1]=0;
        q.push(1);
            
        while(!q.empty()){
            int now=q.front();
            q.pop();
            int nxt=now;
            while(pos[nxt+1]-pos[now]<=d){
                //cout<<nxt<<" ";
                nxt++;
                if(dis[now]+pos[nxt]-pos[now]<dis[nxt]){
                    dis[nxt]=dis[now]+pos[nxt]-pos[now];
                    cnt[nxt]=1;
                    q.push(nxt);
                }else if(dis[now]!=inf&&(dis[now]+pos[nxt]-pos[now])==dis[nxt]) cnt[nxt]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]==2&&pos[i]-pos[1]>d) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}