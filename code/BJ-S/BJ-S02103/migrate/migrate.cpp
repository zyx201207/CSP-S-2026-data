#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t>0){
        int n,d,ans=0,x[1000000];
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(d==2){
            for(int i=1;i<=n;i++){
                if(x[i+3]-x[i]==3){
                    ans+=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
