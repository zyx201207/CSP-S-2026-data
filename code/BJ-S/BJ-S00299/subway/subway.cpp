#include<bits/stdc++.h>
using namespace std;
int c,n,m,k[505],d,q,w[500005],a[500005],t[500005],cnt,u,v;
long long e[2005][2005],lt[100005];
pair<int,long long> p;
vector<pair<int,long long>> to[2005];
struct que{
    int l,r,f,o;
    long long e;
}r[100005];
void in(long long x,int now){
printf("0");
    if(x>=r[now].e){
        if(!r[now].r){
            r[now].r=cnt;
            r[cnt].f=now;
        }else{
            in(x,r[now].r);
        }
    }else{
        if(!r[now].l){
            r[now].l=cnt;
            r[cnt].f=now;
        }else{
            in(x,r[now].l);
        }
    }return;
}
int olt(int now){
    if(r[now].l){
        return olt(r[now].l);
    }else{
        return now;
    }
}
int out(){
    int now=olt(0);
    if(r[now].r){
        r[r[now].f].l=olt(r[now].r);
    }else{
        r[r[now].f].l=0;
    }
    return now;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            e[i][j]=999999999999999ll;
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[j],&t[j]);
        }
        for(int j=1;j<=k[i];j++){
            for(int o=j+1;o<=k[i];o++){
                e[a[j]][a[o]]=min(e[a[j]][a[o]],0ll+t[j]+t[o]);
                e[a[o]][a[j]]=min(e[a[o]][a[j]],0ll+t[j]+t[o]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(e[i][j]!=999999999999999ll){
                p.first=j;
                p.second=e[i][j];
                to[i].push_back(p);
                p.first=i;
                to[j].push_back(p);
            }
        }
    }
    r[0].e=999999999999999ll;
    for(int i=1;i<=q;i++){
        scanf("%d%d",&u,&v);
        for(int j=1;j<=m;j++){
            lt[j]=999999999999999ll;
        }
        lt[u]=0;
        for(auto i:to[u]){
            r[++cnt].o=i.first;
            in(lt[u]+i.second,0);
        }
        while(lt[v]==999999999999999ll){
            int p=out();
            if(lt[r[p].o]){
                continue;
            }
            lt[r[p].o]=r[p].e;
            for(auto i:to[r[p].o]){
                if(!lt[i.first]){
                    r[++cnt].o=i.first;
                    in(lt[r[p].o]+i.second,0);

                }

            }
        }
        printf("%lld\n",lt[v]);
    }
}
