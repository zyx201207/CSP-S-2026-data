#include <bits/stdc++.h>
using namespace std;
int c,t,n,d;
int x[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j)continue;
                if((x[j]-x[i])%d==0) continue;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
