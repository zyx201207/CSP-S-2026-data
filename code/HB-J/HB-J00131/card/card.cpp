#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N],pre[N],now[N];
unordered_map<int,int>mp;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=now[a[i]];
        now[a[i]]=i;
    }
    bool vis[N]={};
    int d[N]={};
    for(int o=1;o<=n;o++){
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof d);
        for(int i=o;i<=n;i++){
            if(vis[a[i]]){
                for(int j=pre[i];j<=i;j++)vis[a[j]]=0;
            }
            vis[a[i]]=1;
        }
        for(int i=1;i<=m;i++){
            if(vis[i])mp[i]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
}
