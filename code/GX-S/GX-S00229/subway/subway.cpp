#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
struct node{
    int a,t;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    node k[505][50005],r[100005];
    for(int i=1;i<=m;i++){
        scanf("%d",w[m]);
    }
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        for(int j=1;j<=2*temp;j++){
            scanf("%d%d",&k[i][j].a,&k[i][j].t);
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",r[i].a,r[i].t);
    }
    return 0;
}
