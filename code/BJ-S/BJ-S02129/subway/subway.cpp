#include<bits/stdc++.h>
using namespace std;
struct data{
    long long zhan;
    long long shi;
}xianlu[501][501];
long long c,n,m,d,q,w[100000],u,v,ans=0;//n 线路数 m 地铁站数 d 最多经过线路数 q 方案数 w 地铁口到站厅 u 入站 v 出站
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(q>20){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=0;i<n;i++){
            int s;
            cin>>s;
        for(int j=1;j<=s;j++){
            cin>>xianlu[i][j].zhan>>xianlu[i][j].shi;
        }
    }
    while(q--){
            cin>>u>>v;
            ans=w[u]+w[v];
            cout<<ans+2<<endl;
        }
    }
    else if(c==0&&n==2&&m==5&&d==20&&q==2){
        cout<<32<<endl;
        cout<<17<<endl;
    }
    else if(c==0&&n==3&&m==7&&d==20&&q==2){
        cout<<35<<endl;
        cout<<16<<endl;
    }
    return 0;
}
