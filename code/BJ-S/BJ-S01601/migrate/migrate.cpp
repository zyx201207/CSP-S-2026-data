#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int NUM=5e3+5;
const ll MAX=2e9+3;

int n,T;
ll x[NUM],d,ans;
ll len[NUM][NUM];
ll s[NUM][NUM];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%d %d",&T,&T);
    while(T--){
      scanf("%d %lld",&n,&d);
      for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
      }
      memset(len,MAX,sizeof(len));
      memset(s,0,sizeof(s));
      ans=0;
      sort(x+1,x+n+1);

      for(int i=1;i<=n;i++){
            len[i][i]=0;
        for(int j=i+1;j<=n;j++){
            if(x[j]-x[i]<=d){
                len[i][j]=1;
                len[j][i]=1;
            }
        }
      }

      for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(len[i][k]!=MAX&&len[k][j]!=MAX){
                    if(len[i][j]>len[i][k]+len[k][j]){
                        len[i][j]=len[i][k]+len[k][j];
                        s[i][j]=1;
                    }
                    if(len[i][j]==len[i][k]+len[k][j]){
                        s[i][j]++;
                    }
                }
            }
        }
      }

      for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            //printf("(%lld)",s[i][j]);
            if(s[i][j]==4){
                ans++;
            }
        }
        //printf("\n");
      }
      printf("%lld\n",ans);

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
