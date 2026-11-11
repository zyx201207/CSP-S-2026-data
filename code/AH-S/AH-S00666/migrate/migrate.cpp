#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000010],n,d;
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--) {
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            sort(a+1,a+n+1);
            long long dd=a[2]-a[1];
            if(d<dd*2) cout<<0<<endl;
            else cout<<n-1<<endl;
        }
    return 0;
}
