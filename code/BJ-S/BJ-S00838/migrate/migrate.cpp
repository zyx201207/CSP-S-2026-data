#include<bits/stdc++.h>
using namespace std;

const int N=5005;
int n,c,t,f[5005][5005];
long long d,x[N],ans;


int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(;t>=1;t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            f[i][i]=1;
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j;k>=i;k--){
                    if(x[j]-x[k]>d)continue;
                    f[i][j]+=f[i][k];
                }
                if(f[i][j]==2){
                    ans++;
                    
                }
                //cout<<f[i][j]<<" ";
            }
        }
        cout<<ans<<"\n";
    }
}
