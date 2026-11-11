#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,m,a[N],b[N],w[N],ans,c,d,q,qd,zd;
pair<int,int> e[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int  a,t;
            scanf("%d%d",&a,&t);
            e[i].first=a;
            e[i].second=t;
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qd,&zd);
        cout<<(qd+zd)*w[1]<<endl;
    }
    return 0;
}
