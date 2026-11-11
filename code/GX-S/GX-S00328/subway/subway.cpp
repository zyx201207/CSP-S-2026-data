#include<bits/stdc++.h>
#define int long long
#define cialo return
using namespace std;
const int N=1e5+10;
int c,n,m,d,y;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
int w[N];
int r,l;
int tim=N;

struct _{
    int a[N],t[N],k;
}q[50];

void dfs(int x,int ti,int re){
    if(ti>tim)return ;
    if(x==r){
        tim=min(tim,ti+w[x]);
        return ;
    }
    if(c>6){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
                if(re==0)re=i;
            dfs(j,ti+q[re].t[x]+q[i].t[j],i);
        }
    }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=q[i].k;j++){
                if(q[i].a[j]==x){
                    for(int k=1;k<=q[i].k;k++){
                        if(k==j)continue;
                        if(re==0)re=i;
                        dfs(k,ti+q[re].t[x]+q[i].t[k],i);
                    }
                    break;
                }
            }
        }
    }
}

void solve(){
    tim=N;
    dfs(l,w[l],0);
    cout<<tim<<endl;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>y;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>q[i].k;
        for(int j=1;j<=q[i].k;j++){
            cin>>q[i].a[j]>>q[i].t[j];
        }
    }
    for(int i=1;i<=y;i++){
        cin>>l>>r;
        solve();
    }
    cialo 0;
}
