#include<bits/stdc++.h>
using namespace std;
int n,D;
int c,t;
int d[2000005],a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>D;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            d[i]=a[i+1]-a[i];
        }
        bool flag=true;
        int k=a[2]-a[1];
        for(int i=1;i<n;i++){
            if(d[i]!=k){
                flag=false;
                break;
            }
        }
        if(flag){
            if(D==2*k){
                cout<<(n-3)<<endl;
            }
            else cout<<0<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}