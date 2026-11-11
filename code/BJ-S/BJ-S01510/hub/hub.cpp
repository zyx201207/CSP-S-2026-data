#include<bits/stdc++.h>
using namespace std;
long long _;
long long t,n,k;
long long head[5000005];
struct E{
    long long v,nxt;
}e[5000005];
long long cnt=1;
void ade(long long u,long long v){
    e[cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}
long long d1[5000005],d2[5000005];

void dfs(long long u,long long fa){
    for(long long i=head[u];i;i=e[i].nxt){
        long long v=e[i].v;
        if(v!=fa){
            dfs(v,u);
            if(d1[u]<d1[v]+1){
                swap(d1[u],d2[u]);
                d1[u]=d1[v]+1;
            }else{
                d2[u]=max(d2[u],d1[v]+1);
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>_>>t;
    while(t--){
        memset(e,0,sizeof(e));
        memset(head,0,sizeof(head));
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        cin>>n>>k;
        for(long long i=1;i<n;i++){
            long long u,v;
            cin>>u>>v;
            ade(u,v);
            ade(v,u);
        }
        dfs(1,0);
        long long wpc=0,ans=0;
        for(long long i=1;i<=n;i++){
            wpc=max(wpc,d1[i]+d2[i]);
        }
        ans=(wpc-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}
