#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long x[200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    if((x[j]-x[i])%d!=0&&(x[j]-x[i])>d){
                        //cout<<x[i]<<" "<<x[j]<<endl;
                        ans++;
                    }
                }
            }
        cout<<ans<<endl;
    }

    fclose(stdin);
   fclose(stdout);
    return 0;
}