#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100005],e[100005];
struct{
    int l,r;
}b[100005];
struct{
    int a,t;
}f[100005][10005];
int k(int a){
    int time=0;
    time+=(w[b[a].l]+w[b[a].r]);

    return time;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>e[i];
        for(int j=1;j<=e[i];j++){
            cin>>f[i][j].a>>f[i][j].t;
        }
    }
    for(int i=1;i<=q;i++){
       cin>>b[i].l>>b[i].r;
       cout<<k(i)<<endl;
    }
    return 0;
}
