#include<bits/stdc++.h>
using namespace std;
int cc,n,m,d,q;
int a[500010],b[510][510],c[510][510];
int dfs(int x,int y,int t){
    if(x==y){
        return t;
    }
    for(int i=1;i<=n;i++){
        if(b[i][1]==x){
            t+=c[i][1];
            dfs(b[i][2],y,t);
        }
        else if(b[i][2]==x){
            t+=c[i][2];
            dfs(b[i][1],y,t);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>cc>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>b[i][j]>>c[i][j];
        }
    }
    if(cc==7||cc==8||cc==9||cc==10||cc==11){
        for(int i=1;i<=q;i++){
            long long t=0;
            int x,y;
            cin>>x>>y;
            t=a[x]+a[y];
            t+=dfs(x,y,0);
            cout<<t<<endl;
        }
    }
    return 0;
}

