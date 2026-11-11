#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
bool visited[maxm];
int n,m,a[maxn],cnt[maxm],ans[maxm],nxt[maxn],lst[maxm],gong[maxm],fa[maxn];
vector<int> dp[maxm],v[maxm];
void dfs(int x,int f){
    for(int i=0;i<v[x].size();i++){
        int dx=v[x][i];
        if(dx==f){
            continue;
        }
        dfs(dx,x);
        gong[x]+=gong[dx];
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    if(m<=3000){
        for(int i=n;i>=1;i--){
            if(!visited[a[i]]){
                visited[a[i]]=true;
                nxt[i]=-1;
                lst[a[i]]=i;
            }
            else{
                nxt[i]=lst[a[i]];
            }
            if(nxt[i]==-1){
                if(nxt[i+1]==-1){
                    dp[i]=dp[i+1];
                }
                else{
                    dp[i]=dp[nxt[i+1]];
                }
                dp[i].push_back(a[i]);
                for(int j=0;j<dp[i].size();j++){
                    ans[dp[i][j]]+=cnt[a[i]];
                }
            }
        }
    }
    else{
        for(int i=n;i>=1;i--){
            if(!visited[a[i]]){
                visited[a[i]]=true;
                nxt[i]=-1;
                lst[a[i]]=i;
                if(i<n){
                    if(nxt[i+1]==-1){
                        gong[a[i+1]]+=cnt[a[i]];
                        fa[a[i]]=a[i+1];
                        v[a[i+1]].push_back(a[i]);
                    }
                    else{
                        gong[a[nxt[i+1]]]+=cnt[a[i]];
                        fa[a[i]]=a[nxt[i+1]];
                        v[a[nxt[i+1]]].push_back(a[i]);
                    }

                }
            }
            else{
                nxt[i]=lst[a[i]];
            }
        }
        dfs(a[n],0);
        for(int i=n;i>=1;i--){
            if(nxt[i]==-1){
                ans[a[i]]+=cnt[a[i]]+gong[a[i]];
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
