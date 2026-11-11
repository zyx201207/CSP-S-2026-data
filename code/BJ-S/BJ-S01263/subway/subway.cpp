#include<iostream>
using namespace std;
int map[5010][5010],b[5010],ans=1e9+10;
int c,n,m,q,d;
void dfs(int place,int end,int cnt){
    if(cnt>ans) return;
    if(place==end){
        ans=min(ans,cnt);
        return;
    }
    for(int i=1;i<=m;i++){
        if(map[place][i]&&!b[i]){
            b[i]=1;
            dfs(i,end,cnt+map[place][i]);
            b[i]=0;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int g[5001]={};
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>g[i];
    for(int i=1;i<=n;i++){
        int k,a[500100]={},t[500100]={};
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            for(int f=1;f<j;f++){
                map[a[f]][a[j]]=t[f]+t[j];
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        b[x]=1;
        dfs(x,y,0);
        cout<<ans+g[x]+g[y]<<endl;
    }
    return 0;
}
