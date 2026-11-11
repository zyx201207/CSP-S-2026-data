#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long a[N],f[N],dis[N],last[N],pre[N],ans,sum[N];
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long d;
        int n;
        ans=0;
        scanf("%d %lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<n;i++){
            //i表示起始点
            memset(f,0,sizeof(f));
            memset(dis,0,sizeof(dis));
            memset(last,0,sizeof(last));
            memset(pre,0,sizeof(pre));
            memset(sum,0,sizeof(sum));
            pre[i]=i;
            dis[i]=0;
            int l=i;
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d){
                    f[j]=1;
                    dis[j]=1;
                    pre[j]=pre[j-1];
                    last[pre[j]]=j;
                }
                else{
                    while(a[j]-a[l]>d){
                        l++;
                    }
                    if(l==j){
                        break;
                    }
                    dis[j]=dis[l]+1;
                    if(dis[j]==dis[j-1]){
                        pre[j]=pre[j-1];
                        last[pre[j]]=j;
                    }
                    else{
                        pre[j]=j;
                        last[j]=j;
                    }
                    long long las=last[pre[l]];
                    las=sum[las]-sum[l-1];
                    f[j]=las;
                }
                sum[j]=sum[j-1]+f[j];
            }
            for(int j=i;j<=n;j++){
                if(f[j]==2){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
