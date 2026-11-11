#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,x[2000006],n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int l=1;l<=t;l++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        ll cha=x[2]-x[1];
        ll minn=(d/cha)+1;
        ll ans=n-minn;
        if(ans<0) ans=0;
        if(cha==d||d==1) ans=0;
        cout<<ans<<endl;
    }
}
