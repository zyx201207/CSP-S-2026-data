#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[1005];
int t[505][1005];
int k[505];
int a[505][1005];
vector<int> to_[505][1005];
vector<int> sub[1005];
bool vis[1005];
int st,ed;
ll ans;
void dfs(int subway,int pos,ll val){
    if(pos==ed){
        ll val_=val+t[subway][pos];
        ans=min(ans,val_);
        return;
    }
    for(int next_sub:sub[pos]){
        for(int next_pos:to_[next_sub][pos]){
            //if(next_sub!=subway&&ti[next_sub]!=0) continue;
            //ti[next_sub]++;
            if(vis[next_pos]) continue;
            vis[next_pos]=1;
            ll val_=val;
            if(next_sub!=subway){
                //cout<<next_sub<<" "<<subway<<"\n";
                //cout<<next_pos
                //cout<<t[next_sub][next_pos]<<" "<<t[subway][next_pos]<<"\n";
                val_+=t[next_sub][pos]+t[subway][pos];
            }
                
            //cout<<next_sub<<" "<<next_pos<<" "<<val_<<"\n";
            dfs(next_sub,next_pos,val_);
            vis[next_pos]=0;
            //ti[next_sub]--;
        }
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][a[i][j]];
            sub[a[i][j]].push_back(i);
        }
        for(int j=1;j<=k[i];j++){
            if(j==1) to_[i][a[i][j]].push_back(a[i][j+1]);
            else if(j==k[i]) to_[i][a[i][j]].push_back(a[i][j-1]);
            else{
                to_[i][a[i][j]].push_back(a[i][j+1]);
                to_[i][a[i][j]].push_back(a[i][j-1]);
            }
        }
    }
    while(q--){
        memset(vis,0,sizeof(vis));
        ans=0x3f3f3f3f3f3f;
        cin>>st>>ed;
        vis[st]=1;
        for(int x:sub[st])
            dfs(x,st,t[x][st]);
        ans+=w[st]+w[ed];
        cout<<ans<<"\n";
        //cout<<"\n";
    }
    return 0;
}