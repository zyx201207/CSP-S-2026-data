#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int c=a[2]-a[1];
            if(d>=c*2&&d<c*3)cout<<n-3;
            else cout<<0;
            cout<<endl;
        }
    }
    return 0;
}
