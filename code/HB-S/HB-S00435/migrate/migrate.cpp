#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5000,INF=3e18;
ll trash,qst,ild,fds,ln[N+5],gh[N+5][N+5],cpl[N+5][N+5],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&trash,&qst);
    while(qst--){
        scanf("%lld%lld",&ild,&fds);
        for(int i=1;i<=ild;i++)scanf("%lld",&ln[i]);
        for(int i=1;i<=ild;i++)for(int j=1;j<=ild;j++)gh[i][j]=INF,cpl[i][j]=0;for(int i=1;i<=ild;i++)gh[i][i]=0;ans=0;
        for(int i=1;i<=ild;i++)for(int j=i+1;j<=ild;j++)if(ln[j]-ln[i]<=fds)gh[i][j]=1;
        for(int k=1;k<=ild;k++)for(int i=1;i<=ild;i++)for(int j=i+1;j<=ild;j++){
            if(i>=k||j<=k)continue;
            if(gh[i][j]==gh[i][k]+gh[k][j])cpl[i][j]++;
            else if(gh[i][j]>gh[i][k]+gh[k][j])gh[i][j]=gh[i][k]+gh[k][j],cpl[i][j]=1;
        }for(int i=1;i<=ild;i++)for(int j=i+1;j<=ild;j++)if(cpl[i][j]==2)ans++;
        printf("%lld\n",ans);
    }return 0;
}
