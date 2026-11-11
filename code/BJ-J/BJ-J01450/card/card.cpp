#include<bits/stdc++.h>
using namespace std;
long long cnt[300005];
int vis[300005];
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        vector<int>v;
        for(int j=i;j<=n;j++){
            if(vis[a[j]]==0){
                vis[a[j]]=v.size()+1;
                v.push_back(a[j]);
            }
            else{
                int c=vis[a[j]]-1;
                for(int x=v.size()-1;x>=c;x--){
                    vis[v[x]]=0;
                    v.pop_back();
                }
                vis[a[j]]=v.size()+1;
                v.push_back(a[j]);
            }
        }
        for(int j:v){
            cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
