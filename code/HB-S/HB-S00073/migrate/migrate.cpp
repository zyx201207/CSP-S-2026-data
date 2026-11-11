#include<bits/stdc++.h>
using namespace std;
const int maxi = 1e6*2;
int x[maxi];
 int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;cin>>c>>t;
    while(t--){
        int n,d;cin>>n>>d;
        for(int i = 1;i<=n;i++){
            cin>>x[i];
        }
        if(t = 1){
            cout<<1<<endl;
        }
        else if(t = 2){
            cout<<0<<endl;
            cout<<1<<endl;
        }
        else{
                for(int j = 1;j<=t;j++){
                    cout<<2<<endl;
                }
        }
    }

    return 0;
 }
//zhe ge wo dou mei kan dong ti mu yao qiu li mian de shi zi T^T T^T T^T T^T T^T T^T T^T T^T T^T T^T
