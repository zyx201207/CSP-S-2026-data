#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[200005];
bool v[200005];
int dfs(int s){
    return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans=0;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=n-i+1;j++){
                ans+=dfs(j+i-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
