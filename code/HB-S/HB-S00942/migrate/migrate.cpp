#include<bits/stdc++.h>
using namespace std;
const int mx=2E6+10;
int a[mx];
int c,T;
int n,d,t;

void solve(){

}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(abs(a[i]-a[i-1])>d) t=i;
        }
        for(int i=1;i<=t;i++){

        }
        solve();
    }
    return 0;
}
