#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;

int w[500005];
vector<int>a[500],t[500];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1; i<=m; ++i){
        scanf("%d",&w[i]);
    }
    for(int i=1; i<=n; ++i){
        int k;
        scanf("%d",&k);
        for(int j=0; j<=k; ++j){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            a[i].push_back(t1);
            t[i].push_back(t2);
        }
    }
    int ans=0;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ans+=w[x]+w[y];
        printf("%d",ans);
    }

    return 0;
}
