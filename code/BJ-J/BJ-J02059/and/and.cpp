#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e3+5;
int n,m;
int a[MAXN];
int mem[MAXN][MAXN];
int ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) mem[1][i]=a[i];
    for(int i=1;i<=n;i++){
        int cnt=1;
        queue<int> q;
        vector<bool> vis(n,0);
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int j=1;j<=n;j++){
                if(vis[j]) continue;
                cnt++;
                mem[cnt][j]=mem[cnt-1][cur]&a[j];
                if(cnt==m){
                    ans=max(ans,mem[cnt][j]);
                    continue;
                }
                vis[j]=true;
                q.push(j);
            }
        }
    }
    cout<<ans;
    return 0;
}
