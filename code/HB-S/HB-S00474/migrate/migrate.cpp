#include<bits/stdc++.h>
using namespace std;
const int M=2e6+50;
long long x[M];
int c,t;
int n,d;
int nxt(int a){
    return upper_bound(x+1,x+n+1,x[a]+d)-x-1;
}
int dis(int s,int e){
    if(s>=e) return 0;
    int l=nxt(s);
    if(l<=s) return -1;
    int k=dis(nxt(s),e);
    if(k==-1) return -1;
    return k+1;
}
int dfs(int s,int e,int dpth){
    if(dpth==0){
        if(s==e) return 1;
        return 0;
    }
    int l=nxt(s),cnt=0;
    for(int i=s+1;i<=l&&i<=e;i++){
        cnt+=dfs(i,e,dpth-1);
    }
    return cnt;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(dis(i,j)==-1) continue;
                if(dfs(i,j,dis(i,j))==2) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
