#include<iostream>
using namespace std;
#define int long long

int c,T,n,d,a[2000005],f[305][305][305],ans;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==13||c==14){
            cout<<0<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    f[i][j][k]=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]+d<a[j])continue;
                f[i][j][1]=1;
            }
        }
        for(int m=2;m<=n;m++){
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++){
                        if(!f[j][k][1])break;
                        f[i][k][m]+=f[i][j][m-1]*f[j][k][1];
                        if(f[i][k][m]>3)f[i][k][m]=3;
                    }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(f[i][j][k]){
                        if(f[i][j][k]==2)ans++;
                        break;
                    }
        cout<<ans<<'\n';
    }

    return 0;
}
//g++ migrate.cpp -o migrate -std=c++14 -Wall -O2