#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int M=5*1e5;
int c,n,m,d,q;
struct node{
    int t1,t2;
    int id;
}E[M];
node road[3][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(n==1){
        for(int i=1;i<=m;i++){
            cin>>E[i].t1;
            E[i].id=i;
        }
        int k;
        for(int i=1;i<=n;i++){
            cin>>k;
            for(int j=1;j<=k;j++){
                int a,b;
                cin>>a>>b;
                E[a].t2=b;
                road[i][j]=E[a];
            }
        }
        while(q--){
            int x,y;
            int st,ed;
            cin>>x>>y;
            for(int i=1;i<=k;i++){
                if(road[1][i].id==x) {st=i;}
                if(road[1][i].id==y) {ed=i;}
            }
            long long ans=road[1][st].t1+road[1][st].t2+road[1][ed].t1+road[1][ed].t2;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
