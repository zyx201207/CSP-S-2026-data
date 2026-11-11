#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long x[N];
int ans=INT_MAX,anst;
void dfs(int u,int e,long long d,int cnt){
    if(u==e){
        if(cnt==ans)
            anst++;
        else if(cnt<ans){
            ans=cnt;
            anst=1;
        }
        return;
    }
    for(int i=u+1;i<=e;i++){
        if(x[i]-x[u]<=d)
            dfs(i,e,d,cnt+1);
        else
            break;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n;
        long long d;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",&x[i]);
        if(11<=c&&c<=12){
            long long d1=x[2]-x[1];
            if(d<2*d1){
                printf("0\n");
                continue;
            }else{
                printf("%d\n",n-3);
                continue;
            }
        }else{
            int cnt=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=INT_MAX;
                    dfs(i,j,d,0);
                    if(anst==2)
                        cnt++;
                }
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
