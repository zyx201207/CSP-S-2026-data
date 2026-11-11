#include<bits/stdc++.h>
using namespace std;
int n,c,t,dis[5001],g[5001][5001];
long long d,a[2000001];
long long f[5001][5001],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(g,0x3f,sizeof(g));
        memset(f,0,sizeof(f));
        ans=0;
        cin>>n>>d;
        if(n<=400){
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]),g[i][i]=0,f[i][i]=1;
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(a[i]+d>=a[j])g[i][j]=1;
                    else break;
                }
            }
            for(int k=1;k<=n;k++){
                for(int i=1;i<=n;i++){
                    for(int j=i;j<=n;j++){
                        if(a[j]-a[k]<=d&&j>=k&&k>=i){
                            if(g[i][j]>g[i][k]+1)g[i][j]=g[i][k]+1,f[i][j]=f[i][k];
                            else if(g[i][j]==g[i][k]+1){
                                if(f[i][k]!=-1)f[i][j]+=f[i][k];
                                else f[i][j]=-1;
                            }
                        }
                        if(f[i][j]>=3)f[i][j]=-1;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(f[i][j]==2)ans++;
                }
            }
            printf("%lld\n",ans);
        }else{
            for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
            int p=0,j=0,k=0;
            for(int i=1;i<=n;i++){
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d)p=i;
            }
            for(int i=p;i<=n;i++){
                if(a[p-1]+d<a[i]){
                    break;
                }
                j=i;
            }
            for(int i=p;i<=n;i++){
                if(a[p-2]+d<a[i]){
                    break;
                }
                k=i;
            }
            for(int i=1;i<=n;i++){
                int l=i,r=n;
                while(l<r){
                    int mid=(l+r+1)/2;
                    if(a[i]+d>=a[mid])l=mid;
                    else r=mid-1;
                }
                if(l==p)ans+=j-k;
                else if(l==p+1)ans+=n-j;
            }
            printf("%d\n",ans);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
