#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],mix,da;
vector<long long> a[505],t[505];
struct node{
    bool ch;
    long long zu,yo,di;
};
vector<node> b;
void dfs(long long x,long long y){
    if(x==y){
        if(da<mix) mix=da;
        return ;
    }
    for(int i=0;i<b.size();i++){
        if(b[i].ch && b[i].zu==x){
            b[i].ch=false;
            long long xz,yz;
            for(int j=0;j<a[x].size();j++){
                if(a[x][j]==b[i].di){
                    xz=j;
                    break;
                }
            }
            for(int j=0;j<a[b[i].yo].size();j++){
                if(a[b[i].yo][j]==b[i].di){
                    yz=j;
                    break;
                }
            }
            da+=t[x][xz]+t[b[i].yo][yz];
            dfs(b[i].yo,y);
            da-=t[x][xz]+t[b[i].yo][yz];
            b[i].ch=true;
        }
        else if(b[i].ch && b[i].yo==x){
            b[i].ch=false;
            long long xz,yz;
            for(int j=0;j<a[x].size();j++){
                if(a[x][j]==b[i].di){
                    xz=j;
                    break;
                }
            }
            for(int j=0;j<a[b[i].zu].size();j++){
                if(a[b[i].zu][j]==b[i].di){
                    yz=j;
                    break;
                }
            }
            da+=t[x][xz]+t[b[i].zu][yz];
            dfs(b[i].zu,y);
            da-=t[x][xz]+t[b[i].zu][yz];
            b[i].ch=true;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++){
        long long k;
        scanf("%lld",&k);
        while(k--){
            long long u,v;
            scanf("%lld %lld",&u,&v);
            a[i].push_back(u);
            t[i].push_back(v);
            for(int j=1;j<i;j++){
                for(int k=0;k<a[j].size();k++){
                    if(a[j][k]==a[i][a[i].size()-1]){
                        node u={true,j,i,a[j][k]};
                        b.push_back(u);
                        break;
                    }
                }
            }
        }
    }
    while(q--){
        mix=1000000000000000000;
        long long x,y;
        scanf("%lld %lld",&x,&y);
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].size();j++){
                if(a[i][j]==x){
                    for(int k=1;k<=n;k++){
                        for(int l=0;l<a[k].size();l++){
                            if(a[k][l]==y){
                                da=w[x]+t[i][j]+w[y]+t[k][l];
                                dfs(i,k);
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n",mix);
    }
    return 0;
}
