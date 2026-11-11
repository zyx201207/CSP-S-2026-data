#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+n+1);
        int cnt=0;
        for(int i=2;i<=n;i++){
            cnt+=abs(x[i]-x[i-1])>d;
        }
        if(d==1||n<=3){
            cout<<"0\n";
            continue;
        }
        cout<<(n-cnt-2*d+1)<<endl;
    }
    return 0;
}
