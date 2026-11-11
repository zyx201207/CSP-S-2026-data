#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            if(d/(a[2]-a[1])>=2){
                long long x=n+1-(d/(a[2]-a[1]))*2;
                if(x>0)cout<<x;
                else cout<<0;
            }
            else cout<<0;
            cout<<endl;
        }
    }
    return 0;
}
