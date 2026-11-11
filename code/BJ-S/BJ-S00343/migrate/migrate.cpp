#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,x[N];
int main(){
    freopen("magrate.in","r",stdin);
    freopen("magrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<4){
            cout<<"0"<<endl;
        }
        else{
            int ans=0;
            for(int i=1;i<=n-4;i++){
                for(int j=i+4;j<=n;j++){
                    if((j-i+1)%d==1){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
