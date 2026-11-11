#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,i,n,j,d;
    cin>>c>>t;
    for(i=1;i<=t;i++){
        int a[1000001],ans=0;
        cin>>n>>d;
        for(j=1;j<=n;j++){
            cin>>a[j];
        }
        int p=a[2]-a[1],m=d/p;
        for(int k=2;k<=m;k++){
            ans+=n-2*k+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
