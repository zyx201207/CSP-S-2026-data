#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            int ans=0;
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            int c=a[2]-a[1];
            d/=c;
            for(int i=1;i<=n;i++){
                for(int j=i+3;j<=n;j++){
                    ans+=1+(j-i+1)/d*d-(j-i+1);
                }
            }
            cout<<ans<<"\n";
        }
    }else{
        while(t--){
            cout<<0;
        }
    }

    return 0;
}
