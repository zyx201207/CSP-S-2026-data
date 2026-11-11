#include <bits/stdc++.h>
using namespace std;
int b[500001],c,n,m,d,q,a7[1010][1010];
void di(int x,int y){
    long long dis[1010],vis[1010];
    for(int i=1;i<=1010;i++){
        dis[i]=1e18;
        vis[i]=0;
    }
    dis[x]=0;
    for(int i=1;i<=m+n;i++){
        int th=1e9;
        for(int j=1;j<=n+m;j++)if(th==1e9&&!vis[j])th=j;
        if(th==1e9){
            cout<<dis[y]+b[x]+b[y]<<endl;
            return;
        }
        for(int j=1;j<=n+m;j++)if(!vis[j]&&dis[j]<dis[th])th=j;
        vis[th]=1;
        for(int j=1;j<=n+m;j++)if(a7[th][j]&&dis[j]>dis[th]+a7[th][j])dis[j]=dis[th]+a7[th][j];
    }
    cout<<dis[y]+b[x]+b[y]<<endl;
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    if(c>=7&&c<=11){
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            int a1,a2,a3,a4;
            cin>>a1>>a2>>a3>>a4;
            a7[a1][a3]=a2+a4;
            a7[a3][a1]=a2+a4;
        }
        n=0;
    }else{
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            for(int j=1;j<=x;j++){
                int a1,a2;
                cin>>a1>>a2;
                a7[a1][m+i]=a2;
                a7[m+i][a1]=a2;
            }
        }
    }
    while(q--){
        int q1,q2;
        cin>>q1>>q2;
        di(q1,q2);
    }
    return 0;
}
