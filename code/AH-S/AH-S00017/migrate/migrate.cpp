#include<iostream>
#define int long long
#include<cstdio>
using namespace std;
int C,t,n,d,a[2000005],f[2000005][2],ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            f[i][0]=0;
            f[i][1]=0x3f3f3f3f;
        }
        f[1][0]=1;
        f[1][1]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            int j=i-1;
            while(j>=1){
                if(a[i]-a[j]>d) break;
                if(f[j][1]+1<f[i][1]){
                    f[i][1]=f[j][1]+1;
                    f[i][0]=1;
                }else if(f[j][1]+1==f[i][1]){
                    f[i][0]++;
                }
                j--;
            }
            if(f[i][0]==2) ans++;
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
