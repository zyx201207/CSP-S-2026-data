#include<bits/stdc++.h>
#define re register
using namespace std;
int n,m;
int a[500010];
int tong[300100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(re int i=1;i<=n;i++){
        vector<pair<bool,int> >vis(m+1);
        for(int j=1;j<=m;j++)vis[i].second=vis[i].first=0;
        int tail=0;
        int q[500010];
        memset(q,0,sizeof(q));
        for(re int j=i;j<=n;j++){
            if(vis[a[j]].first==0){
                q[++tail]=j;
                vis[a[j]].first=1;
                vis[a[j]].second=tail;
            }
            else{
                q[vis[a[j]].second]=j;
                tail=vis[i].second;
            }
        }
        for(re int j=1;j<=tail;j++)tong[a[q[j]]]++;
    }
    for(re int i=1;i<=m;i++)printf("%d ",tong[i]);
    return 0;
}
