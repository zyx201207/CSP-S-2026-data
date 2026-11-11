#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n=0,d=0;
        memset(x,0,sizeof(x));
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(d<(x[2]-x[1])*2)cout<<"0"<<endl;
        else{
            int b;
            bool ok=false;
            for(int i=1;i<=n;i++){
                if((x[i]-x[1])%d==d-1&&(x[i]-x[1])/d==1){
                        b=i;
                        ok=1;
                        //cout<<" i= "<<i;
                }
                if(ok)break;
            }
            int ans=n-b+1;
            cout<<ans<<endl;
        }
    }
    return 0;
}
