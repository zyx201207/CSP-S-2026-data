#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin >> c >> t;
    int a[100005];
    while(t--){
        int sum=0;
        int n,d;cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]<=d&&j-i==1){
                    for(int z=j+1;z<=n;z++){
                        if(a[z]-a[j]<=d&&z-j==2&&a[z]-a[i]>d){
                            sum++;
                        }
                    }
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}
