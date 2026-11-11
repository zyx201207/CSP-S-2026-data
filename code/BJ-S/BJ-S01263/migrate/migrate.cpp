#include<iostream>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        long long ans=0,a[50010]={};
        int n;
        long long m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=i-3;j>=1;j--){
                if(a[i]-a[j+1]<=m&&a[i]-a[j+2]<=m&&a[i]-a[j]>m&&a[j+1]-a[j]<=m&&a[j+2]-a[j]<=m) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
