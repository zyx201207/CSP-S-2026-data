#include<bits/stdc++.h>
using namespace std;
#define MAX 500010
int c,n,m,d,q,w[MAX],k[505],a[505][MAX],x[100005],y[100005],fa[MAX],jie[MAX];
int boss(int x){
    if(fa[x]==x) return x;
    fa[x]=boss(fa[x]);
    return fa[x];
}
void un(int u,int v){
    u=boss(u);
    v=boss(v);
    if(u>v) swap(u,v);
    fa[u]=v;
    v+=u;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);


    return 0;
}
