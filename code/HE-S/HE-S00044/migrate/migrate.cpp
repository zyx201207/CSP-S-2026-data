#include<bits/stdc++.h>
using namespace std;
long long a[2000050];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int l=1;l<=t;l++){
        long long n,d,f;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        f=a[2]-a[1];
        if(d/f<=1){
            cout<<0<<endl;
        }else{
            if(n-d/f*2+1>0){
                cout<<n-d/f*2+1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}
