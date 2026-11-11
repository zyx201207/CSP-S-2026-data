#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int ans=0;
        int n,d;
        cin>>n>>d;
        int a[20];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=3){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                if(a[j]-a[i]<=d||a[j]-a[i]>=2*d) continue;
                for(int k1=i+1;k1<=j-2;k1++){
                    for(int k2=i+2;k2<=j-1;k2++){
                        if(a[k1]-a[i]<=d&&a[j]-a[k1]<=d&&a[k2]-a[i]<=d&&a[j]-a[k2]<=d){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
