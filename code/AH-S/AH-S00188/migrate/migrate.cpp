#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(n<3){
            cout<<0<<endl;
            continue;
        }
        if(d<a[2]-a[1]||d<a[3]-a[1]){
            cout<<0<<endl;
            continue;
        }
        d/=(a[2]-a[1]);
        cout<<n-2*d+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
