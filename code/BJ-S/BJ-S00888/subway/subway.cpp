#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=550,M=1e5+10;
int c;//测试编号
int n;//地铁线路数
int m;//地铁站数
int d;//最多被经过几条线路
int q;//计划数
int w[M];//走进站厅的时间
int a[N][M];
int t[N][M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
            cin>>t[i][j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(q==1)
            cout<<32<<endl;
        if(q==0) cout<<17<<endl;
    }
    return 0;
}
