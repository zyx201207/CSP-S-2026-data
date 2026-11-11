#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+1;
int w[N];
struct{
    int a,t;
}g[N];
int main(){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
            int k;
            cin>>k;
        for(int j=1;j<=k;j++){
            int u,w;
            cin>>u>>w;
            if(k<=2){
                g[i].a=u;
                g[u].t+=w;
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        int num=0,flag=0;
        for(int i=1;i<=m;i++){
            if(g[i].a==x){
                flag=1;
            }
            if(flag==0) continue;
            num+=g[i].t;
            num+=w[x];
            if(g[i].a==y) break;
        }
        cout<<num<<'\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
2 1 5 2 7
2 2 3 3 4
1 3
1 2
*/
