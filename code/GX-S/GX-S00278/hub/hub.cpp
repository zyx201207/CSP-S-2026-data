#include<bits/stdc++.h>
using namespace std;
int c,q,n,k,dis[1005][1005];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>q;
    while(q--){
        cin>>n>>k;
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            dis[u][v]=dis[v][u]=1;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<(1<<n);i++){
            int cnt=0,tmp=i;
            while(tmp){
                cnt+=(tmp&1);
                tmp>>=1;
            }
            if(cnt!=k) continue;
            vector<int> s;
            for(int j=1;j<=n;j++){
                if(i&(1<<j-1)){
                    s.push_back(j);
                }
            }
            int now=0;
            for(int j=1;j<=n;j++){
                if(i&(1<<j-1)) continue;
                int mn=1e9;
                for(int i=0;i<s.size();i++){
                    mn=min(mn,dis[j][i]);
                }
                now=max(now,mn);
            }
            ans=min(now,ans);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//What a diffcult contest!
//100+[24,44]+[24,48]+[0,15]=[144,203]
