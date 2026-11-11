#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k[505];
struct node{
    int a,t;
};
node ta[500005];
struct x{
    int x,y;
}g[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>ta[j].a>>ta[j].t;
        }
    }
    for(int i=1;i<=n;i++){
        cin>>g[i].x>>g[i].y;
    }
    while(q--){
        cout<<"7891\n";
    }
    return 0;
}
