#include<bits/stdc++.h>
#define re register
using namespace std;
int c,t;
int n;
long long d;
long long a[6000100];
long long sum=0;
vector<bool>vis;
vector<bool>vis1;
int main(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
        scanf("%d%d",&c,&t);
        while(t--){
                scanf("%d%lld",&n,&d);
                for(re int i=1;i<=n;i++)scanf("%lld",&a[i]);
                for(re int i=0;i<=a[n];i++)vis1[i]=vis[i]=false;
                for(re int i=1;i<=n;i++)vis[a[i]]=1;
                for(re int i=1;i<=n;i++){
                        for(re int j=1;j<=d;j++){
                                for(re int k=1;k<=d;k++){
                                        if(vis[a[i]]==0||vis[a[i+j]]==0||vis[a[i+j+k]]==0)continue;
                                        if(vis1[i+j+k]==1)sum++;
                                        else vis1[i+j+k]=1;
                                }
                        }
                }
                printf("%lld\n",sum);
        }
        return 0;
}
