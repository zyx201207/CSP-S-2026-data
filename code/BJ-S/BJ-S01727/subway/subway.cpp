#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=5e5+5;
struct dt{
    int ln,t;
};
int rdit(){
    int c=getchar(),f=1,k=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())k=k*10+(c^48);
    return k*f;
}
void writell(long long x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)writell(x/10);
    putchar(x%10+'0');
    return;
}
int c,n,m,d,q,w[maxm],k[maxn];
long long cst[maxn][maxn];
vector<dt>ct[maxm];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rdit(),n=rdit(),m=rdit(),d=rdit(),q=rdit();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)cst[i][j]=(long long)1e15;
    for(int i=1;i<=m;i++)w[i]=rdit();
    for(int i=1;i<=n;i++){
        k[i]=rdit();
        for(int j=1;j<=k[i];j++){
            int a;
            dt tmp;
            cin>>a>>tmp.t;
            tmp.ln=i;
            ct[a].push_back(tmp);
        }
    }
    for(int i=1;i<=m;i++){
        for(int ln1=0;ln1<ct[i].size();ln1++){
            for(int ln2=ln1+1;ln2<ct[i].size();ln2++){
                dt u=ct[i][ln1],v=ct[i][ln2];
                if(cst[u.ln][v.ln]>u.t+v.t){
                    cst[u.ln][v.ln]=(long long)u.t+v.t;
                    cst[v.ln][u.ln]=(long long)u.t+v.t;
                }
            }
        }
    }
    for(int md=1;md<=n;md++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cst[i][j]=min(cst[i][j],cst[i][md]+cst[md][j]);
            }
        }
    }
    while(q--){
        int x=rdit(),y=rdit();
        long long ans=LONG_LONG_MAX;
        for(auto l1:ct[x]){
            for(auto l2:ct[y]){
                ans=min(ans,cst[l1.ln][l2.ln]+l1.t+l2.t);
            }
        }
        writell(ans+w[x]+w[y]);
        putchar('\n');
    }
    return 0;
}
