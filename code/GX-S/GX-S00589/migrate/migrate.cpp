#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,T,n,m,x[N],ans,a,b;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        a=(n-1)%2;
        b=n%2;
        //for(int i=1;i<=n;i++)cin>>x[i];
        if(m>=n-1 or m==1){
            cout<<0<<endl;
            continue;
        }
        if(a==0 and b==0){
            cout<<0<<endl;
            continue;
        }
        for(int j=m+1;j<=2*m-1;j++){
            ans+=n-j;
        }
        cout<<ans<<endl;
    }
    return 0;
}
