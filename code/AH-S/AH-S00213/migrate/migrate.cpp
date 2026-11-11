#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,s[2000005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        int k=s[2]-s[1];
        if(k*2>d||n<(d/k)*2){
            cout<<"0\n";
        }else{
            cout<<n-(d/k)*2+1<<"\n";
        }
    }
    return 0;
}
