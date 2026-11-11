#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
struct node{
    int a,t;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[M],k[N];
    node mp[N][M];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>mp[i][j].a>>mp[i][j].t;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;

    }
    return 0;
}
