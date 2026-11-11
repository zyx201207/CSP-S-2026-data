#include<iostream>
using namespace std;
const int N=5e3+5;
int c,t,n;
long long d,x[N],dist[N][N],cnt[N][N],ans;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=k && j!=k && dist[i][j]==dist[i][k]+dist[k][j]) cnt[i][j]++,cnt[j][i]++;
                else if(dist[i][j]>dist[i][k]+dist[k][j]) dist[j][i]=dist[i][j]=dist[i][k]+dist[k][j],cnt[i][j]=cnt[j][i]=1;

            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt[i][j]=1;
                if(i!=j) dist[i][j]=2e18;
                else dist[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[j]-x[i])<=d){
                    dist[i][j]=dist[j][i]=1;
                }
            }
        }
        floyd();
        for(int i=2;i<=n;i++) for(int j=1;j<i;j++) if(cnt[i][j]==4) ans++;
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
