#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[300005];
bool vis[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    deque<int> q;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==1){
                while(q.back()!=a[j]){
                    vis[q.back()]=0;
                    q.pop_back();
                }
                q.pop_back();
                q.push_back(a[j]);
                vis[a[j]]=1;
            }
            else{
                q.push_back(a[j]);
                vis[a[j]]=1;
            }
        }
        while(!q.empty()){
            cnt[q.front()]++;
            q.pop_front();
        }
        memset(vis,0,sizeof(vis));
       /* for(int i=1;i<=m;i++){
            cout<<cnt[i]<<" ";
        }
        cout<<'\n';
        */
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
