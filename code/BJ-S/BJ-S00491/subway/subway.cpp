#include<bits/stdc++.h>
using namespace std;
const N=1e5*5+8;
bool d[N];
int w[N],k[N],x[N],y[N],b[N],a[N][N],t[N][N];
int c,n,m,d,q,k,sum=0;
int dfs(int s,int x,int y){
    int cnt;
    if(s==y){
        cout<<cnt;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!d[i]){
            d[i]=true;
            b[s]=i;
            dfs(s+1,x+1,y);
            d[i]=false;
            return;
        }
    }
}
int main(){
    for(int i=1;i<=N-1;i++){
        d[i]=false;
    }
    freopen("subway.in",r,stdin);
    freopen("subway.out",w,stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j]
        }
    }
    for(int r=1;r<=q;r++){
        cin>>x[r]>>y[r];
        if(t[1][1]==t[2][2]){
            sum=(y[r]-x[r])*t[1][1];
            cout<<sum;
        }else{
            dfs(1,x[r],y[r]);
        }
    }

    return 0;
}
