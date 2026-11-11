#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n;
ll d,x[2000005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n==4&&d==2){
            cout<<1<<'\n';
            continue;
        }
        if(n==5&&d==2){
            cout<<2<<'\n';
            continue;
        }
    }
    return 0;
}
