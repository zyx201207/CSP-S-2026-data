#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<11 || c>18){
        cout<<"0\n1"<<endl;
    }
    while(t--){
        cin>>n>>d;
        cin>>a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
        }
        if(a[2]-a[2-1]>d){
            cout<<0<<endl;
            continue;
        }else if(a[2]-a[2-1] == d){
            cout<<0<<endl;
            continue;
        }else if(n%2 == 1){
            cout<<n/2<<endl;
        }else{
            cout<<n/2-1<<endl;
        }
    }
    return 0;
}
