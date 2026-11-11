#include<bits/stdc++.h>
using namespace std;

long long n,c,t,d,a[50005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long t1=a[2]-a[1];
        if(d<2*t1){
            cout<<0<<endl;
        }
        else{
            cout<<n-2<<endl;
        }

    }
    return 0;
}
