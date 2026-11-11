#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n;
        int a[n+1];
        long long ans=0;
        int f[n+1];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            f[i]=0;
        }
        for(int i=2+d;i<=n;i++){
            if(a[i]-a[i-1]>d){
                break;
            }
            if((n-i)%d!=0){
                f[i]=f[i]+(i-1)%d;
                f[i]++;
                for(int j=2;j<=i;j+=d){
                    for(int k=j;k<j+d-1;k++){
                        f[k]++;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(f[i]==2){
                    ans++;
                }
            }
            cout<<ans/2<<"\n";
        }
    }
    return 0;
}