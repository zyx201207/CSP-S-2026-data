#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,ans=0;
int x[1000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=n;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
    }
    for(int i=1;i<=n;i++){
         if(x[i]-x[1]==x[i-1]){
            ans++;
       }
    }
    cout<<ans;
    return 0;
}
