#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=12&&c>=11){
        while(t--){
            int a,b,n,x,xxxxxxxx;
            cin>>n>>x;
            cin>>a>>b;
            for(int i=2;i<n;i++)cin>>xxxxxxxx;
            if(abs(a-b)<=x){
                cout<<n-1<<"\n";
            }else cout<<0<<"\n";

        }
    }
    return 0;
}
