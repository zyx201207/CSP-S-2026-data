#include<bits/stdc++.h>
using namespace std;
int f1[5010][5010],f2[5010][5010],f3[5010][5010];
long long x[5010];
int c,t,n,m;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(f1,0x3f,sizeof(f1));
        memset(f2,0x3f,sizeof(f2));
        memset(f3,0,sizeof(f3));
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
            if(abs(x[i]-x[j])<=m){
                f1[i][j]=f1[j][i]=1;
            }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=k &&j!=k){

                    }
                }
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i!=k &&j!=k){
                        f2[i][j]=min(f2[i][j],f2[i][k]+f2[j][k]);
                        if(f2[i][j]==f1[i][j]){
                            f3[i][j]++;
                        }
                    }
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(f3[i][j]==2)cnt++;
            }
        }cout<<cnt<<"\n";
    }
}
