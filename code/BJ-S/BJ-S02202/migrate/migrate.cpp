#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t,c;
    cin>>c>>t;
    while(t--){
        int n,d1,a[2000005],f=0;
        cin>>n>>d1;
        int d=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        d=a[2]-a[1];
        for(int i=3;i<=n;i++){
            if(a[i]-a[i-1]!=d){
                f=1;
            }
        }
        if(f==0){
            int m=d1/d;
            if(n>=2*m){
                cout<<n-m-1;
            }else{
                cout<<0;
            }
        }else{
            cout<<0;
        }
    }
    return 0;
}
