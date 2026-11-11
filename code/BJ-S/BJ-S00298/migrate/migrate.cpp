#include<bits/stdc++.h>
using namespace std;
const long long INF=0x3f3f3f3f3f3f3f3f;
long long w[5005][5005],r[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long n,d,x[200005];
        long long ans=0;
        memset(w,0x3f,sizeof(w));
        cin>>n>>d;
        cin>>x[1];
        for(long long i=2;i<=n;i++){
            cin>>x[i];
            for(long long j=i-1;j>=1;j--){
                if(x[i]-x[j]<=d){
                    w[j][i]=1;
                    r[j][i]=1;
                }
            }
        }

        for(long long i=1;i<=n;i++){
            for(long long j=i+2;j<=n;j++){
                if(w[i][j]!=1){
                    for(long long k=i+1;k<j;k++){
                        if(w[i][k]!=INF&&w[k][j]!=INF){
                            if(w[i][j]>w[i][k]+w[k][j]) w[i][j]=w[i][k]+w[k][j],r[i][j]=1;
                            else if(w[i][j]==w[i][k]+w[k][j]) r[i][j]+=(r[i][k]*r[k][j]);
                            if(r[i][j]>=3) r[i][j]=3;
                        }
                    }
                }
                if(r[i][j]==2) ans++;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
