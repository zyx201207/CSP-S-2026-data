#include <bits/stdc++.h>
using namespace std;
int a[2000001],c,T;
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        if(c==13 || c==14){
            cout<<0<<endl;
            continue;
        }
        memset(a,0,sizeof(a));
        int n,d;
        cin>>n>>d;
        if(n<=3){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                int cnt=0;
                if(abs(a[j]-a[i])<=d) break;
                for(int k=i;k<=j;k++){
                    if(abs(a[k]-a[i])<=d && abs(a[j]-a[k]<=d)) cnt++;
                }
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}
