#include<bits/stdc++.h>
//#define int long long
using namespace std;
int a[5050];
int c,t;
int n,d;
int i,j;

void work(){
    int i,j,ans=0;
    cin>>n>>d;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[2]-a[1]>d){
        cout<<0<<endl;
        return ;
    }
    ans=n-3;
    cout<<ans<<endl;
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        work();
    }
    return 0;
}
