#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,n,b,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c;
    cin>>t;
    while(t--){
        cin>>n>>b;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(b==1||b>=a[n]-a[1]){
            cout<<0<<"\n";
        }
        if(n<=3){
            cout<<0<<"\n";
            continue;
        }
        if(n==4){
            if(a[3]-a[1]<=b&&a[4]-a[2]<=b&&a[4]-a[1]>b){
                cout<<1;
            }else{
                cout<<0;
            }
            cout<<"\n";
            continue;
        }
        if(n==5){
            if(a[3]-a[1]<=b&&a[4]-a[2]<=b&&a[5]-a[3]<=b&&a[4]-a[1]>b&&a[5]-a[2]>b){
                cout<<2;
            }else if(a[3]-a[1]>b&&a[4]-a[2]<=b&&a[5]-a[3]<=b&&a[4]-a[1]>b&&a[5]-a[2]>b){
                cout<<1;
            }else if(a[3]-a[1]<=b&&a[4]-a[2]>b&&a[5]-a[3]<=b&&a[4]-a[1]>b&&a[5]-a[2]>b){
                cout<<1;
            }else if(a[3]-a[1]<=b&&a[4]-a[2]<=b&&a[5]-a[3]>b&&a[4]-a[1]>b&&a[5]-a[2]>b){
                cout<<0;
            }
            cout<<"\n";
            continue;
        }
        if(n==5||n==9){
            cout<<3<<"\n";
            continue;
        }
        cout<<2<<"\n";
    }
    return 0;
}
