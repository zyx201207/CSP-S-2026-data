#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e6+5;
int n;
ll d,a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            if(a[2]-a[1]>=d){
                cout<<0<<'\n';
                continue;
            }
            ll cnt=d/(a[2]-a[1]);
            if(cnt>=n-1) cout<<0<<'\n';
            else cout<<n-cnt*2+1<<'\n';
        }
    }
    return 0;
}