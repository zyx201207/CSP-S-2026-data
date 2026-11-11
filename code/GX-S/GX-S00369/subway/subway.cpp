#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,num,head[500001],w[500001],k[500001],v[500001],root[501],dism[501][250001][2];
int t[501][250001];
struct edge{
    int to,i,last;
}e[1000001];
struct po{
    int v,dis,ei;
    po(){}
    po(int V,int Dis,int E){
        v=V;
        dis=Dis;
        ei=E;
    }
    friend bool operator<(po x,po y){
        return x.dis>y.dis;
    }
};
priority_queue<po> Q;
void add(int from,int to,int i){
    e[++num].to=to;
    e[num].i=i;
    e[num].last=head[from];
    head[from]=num;
}
int s[250001][21],f[250001][501];
void dij(int s,int I){
//    memset(f,0,sizeof(f));
    f[s][I]=0;
    dism[I][s][1]=t[I][s];
    dism[I][s][0]=I;
    for(int i=head[s];i;i=e[i].last){
        if(e[i].i!=I){
            f[e[i].to][e[i].i]=t[I][s]+t[e[i].i][s];
            dism[I][e[i].to][1]=t[I][s]+t[e[i].i][s]+t[e[i].i][e[i].to];
            dism[I][e[i].to][0]=e[i].i;
            Q.push(po(e[i].to,t[I][s]+t[e[i].i][s],e[i].i));
        }
        else{
            f[e[i].to][I]=0;
            dism[I][e[i].to][1]=t[I][e[i].to];
            dism[I][e[i].to][0]=I;
            Q.push(po(e[i].to,0,I));
        }
    }
    while(!Q.empty()){
        po x=Q.top();
        Q.pop();
        for(int i=head[x.v];i;i=e[i].last){
            int ndis=x.dis+((e[i].i==x.ei)?0:t[x.ei][x.v]+t[e[i].i][x.v]);
            if(ndis+t[e[i].i][e[i].to]<dism[I][e[i].to][1]){
                dism[I][e[i].to][1]=ndis+t[e[i].i][e[i].to];
                dism[I][e[i].to][0]=e[i].i;
                f[e[i].to][e[i].i]=ndis;
                Q.push(po(e[i].to,ndis,e[i].i));
            }
            else if(dism[I][e[i].to][0]!=e[i].i&&ndis<dism[I][e[i].to][1]+t[e[i].i][e[i].to]){
                f[e[i].to][e[i].i]=ndis;
                Q.push(po(e[i].to,ndis,e[i].i));
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            dism[j][i][1]=0x7fffffff;
        scanf("%d",w+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",k+i);
        for(int j=1,x,l;j<=k[i];j++){
            scanf("%d",&x);
            scanf("%d",&t[i][x]);
            s[x][++s[x][0]]=i;
            if(j>1){
                add(l,x,i);
                add(x,l,i);
            }
            else
                root[i]=x;
            l=x;
        }
    }
    for(int i=1;i<=n;i++)
        dij(root[i],i);
    for(int i=1,x,y;i<=q;i++){
        scanf("%d%d",&x,&y);
        int mi=0x7fffffff;
        for(int j=1;j<=s[x][0];j++)
            mi=min(mi,t[s[x][j]][x]+dism[s[x][j]][y][1]);
        printf("%d\n",mi+w[x]+w[y]);
    }
    return 0;
}

