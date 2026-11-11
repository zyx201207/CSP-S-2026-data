#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v;
int last[300010],cnt[300010];
bool vis[500010];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=1;i<=m;i++){
        last[i]=-1;
    }
    for(int i=1;i<=n;i++){
        memset(last,0,sizeof(last));
        memset(vis,0,sizeof(vis));
        for(int j=0;j<v.size();j++){
            if(last[v[i]]==-1){
                last[v[i]]=j;
            }
            else{
                for(int k=last[v[i]];k<j;k++){
                    vis[k]=1;
                }
                last[v[i]]=-1;
            }
        }
        for(int j=0;j<v.size();j++){
            if(!vis[j]){
                cnt[v[j]]++;
            }
        }
        v.erase(v.begin());
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}