#include <bits/stdc++.h>

using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,a[N],b[N],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t!=0){
        t--;
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=4;i<=n;i++){
                for(int j=1;j<=i-3;j++){
                    if((a[i]-a[j])%d!=0&&i-j<4){
                                ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}
