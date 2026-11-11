#include<bits/stdc++.h>
#define M 500005
using namespace std;
long c,n,m,d,q;
int strt,nd,eCnt;
int a[501][20],t[201][20],k[501],idt[M][501];
int head[M],eid[M],to[1001],nxt[1001],w[M];
long long ans=LLONG_MAX;
void add(int u,int v,int id){
    eCnt++;
    to[eCnt]=v;
    nxt[eCnt]=head[u];
    head[u]=eCnt;
    eid[eCnt]=id;
}
/*
struct Edge{
    int u,v,id;
}edge[1005];
void add(int u,int v,int id){
    cnt++;
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].id=id;
}
*/
void solve(int strt,int nd,long long sumt){
    int las=0;
    for(int i=head[strt];i;i=nxt[i]){
        cout<<1<<" ";
        int raw=to[i];
        int id1=eid[las],id2=eid[i];
        if(id1!=id2){//need to change lines
            int p=to[las];
            sumt+=(idt[p][id1]+idt[p][id2]);
        }
        if(raw==nd){
            ans=min(ans,sumt);
        }
        las=i;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            if(j>1){
                add(a[i][j],a[i][j-1],i);
                add(a[i][j-1],a[i][j],i);
            }
            idt[a[i][j]][i]=t[i][j];
        }
    }
    /*
    cout<<eCnt<<endl;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=2;j++){
            cout<<idt[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    while(q--){
        cin>>strt>>nd;
        solve(strt,nd,0);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
