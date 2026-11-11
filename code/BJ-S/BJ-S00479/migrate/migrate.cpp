#include <iostream>
using namespace std;
int x[10005];
int f(int a,int b,int d){
    if(d==2){
        return (b-a+1)%2;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int C,T;
    cin>>C>>T;
    while(T--){
        int n,d,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int cvj=f(i,j,d);
                ans+=cvj;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
