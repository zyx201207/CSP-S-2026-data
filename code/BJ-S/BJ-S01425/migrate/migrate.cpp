#include<bits/stdc++.h>
using namespace std;
int xx[2000005];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>xx[i];
        }
        int ans=0;
        for(int i=1;i<=n-3;i++){
            if((xx[i+3]-xx[i])%d>=xx[2]-xx[1]){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
}