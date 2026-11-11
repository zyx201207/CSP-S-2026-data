#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d,a[2000009];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--){
        int q=1;
        long long c,ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        c=a[2]-a[1];
        for(int i=3;i<=n;i++){
            if(a[i]-a[i-1]!=c)q=0;
        }
        if(q==1){
            cout<<0<<'\n';
            continue;
        }
        cout<<2<<'\n';
    }
    return 0;
}
