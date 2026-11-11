#include<bits/stdc++.h>
using namespace std;
    int c,d,n,m,w[500005],qu,k[500005],book[505][505],t[500005][505],in[505][500005],cnt[505][505],ans=0,res=0;
    vector <int> e[500005];
    queue<int>q;
    void dfs(int u,int ending,int sum){
        if(in[u][ending]==1){
            res=1;
            sum+=t[ending][u];
            if(ans==0)ans=sum;
            else ans=min(ans,sum);
            return ;
        }
        if(res==1&&sum>=ans)return ;
        for(int i=1;i<=n;i++){
            if(book[u][i]){
                dfs(i,ending,sum+book[u][i]);
            }
        }
        return ;
    }
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qu;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int a;
            cin>>a>>t[a][i];
            in[i][a]=1;
            for(int u=0;u<e[a].size();u++){
                int v=e[a][u];
                if(book[v][i]<t[a][i]+t[a][v]||book[v][i]==0){
                    book[v][i]=book[i][v]=t[a][i]+t[a][v];
                }
            }
            e[a].push_back(i);
        }
    }
    //for(int i=1;i<=m;i++)cout<<e[i].size()<<" ";
    //int l,r;
    //cin>>l>>r;
    //cout<<book[l][r]<<' '<<book[r][l]<<endl;
    /*cnt[1]=1;

    q.push(1)
    while(!q.empty()){
        int u=q.front();
        for(int i=1;i<=n;i++){
            if(book[u][i]&&cnt[u][i]==0){
                cnt
            }
        }

        q.pop();
    }*/
    for(int i=1;i<=qu;i++){
        ans=res=0;
        int l,r;
        cin>>l>>r;
        //cout<<l<<' '<<r<<endl;
        for(int j=0;j<e[l].size();j++){
            dfs(e[l][j],r,w[l]+w[r]+t[l][e[l][j]]);
        }

        cout<<ans<<endl;
    }

return 0;}
