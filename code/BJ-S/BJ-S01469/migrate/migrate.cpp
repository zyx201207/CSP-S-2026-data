#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
ull c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        ull n,d,a[2000010],ans=0;
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        int nu=d/(a[2]-a[1]);
        for(int j=1;j<=n;j++){
            for(int k=j+nu;k<=n;j++){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
