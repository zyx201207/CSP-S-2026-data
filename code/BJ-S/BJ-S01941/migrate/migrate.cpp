#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,d;
ll x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int tt=1;tt<=t;tt++){
        //cout<<tt<<endl;
        int dm;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        dm=(int)((float)d/(x[2]-x[1]));
        //cout<<d<<' '<<x[2]<<' '<<x[1]<<' '<<dm<<endl;
        if(dm<2||dm>=n) cout<<0<<endl;
        else if(dm==2){
            cout<<n-3<<endl;
        }
        else{
            cout<<n-(2*dm-1)<<endl;
        }
    }
    return 0;
}
