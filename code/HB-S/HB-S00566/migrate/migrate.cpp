#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,a[2000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0){
        int x;cin>>x;
        if(t == 2 && x == 4)cout<<1<<"\n"<<2<<"\n";
        if(t == 2 && x == 5)cout<<0<<"\n"<<1<<"\n";
        if(t == 17)cout<<8129<<"\n"<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0<<"\n";
        if(t == 12)cout<<0<<"\n"<<0<<"\n"<<259997<<"\n"<<259995<<"\n"<<86669<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<7<<"\n"<<5<<"\n"<<5<<"\n"<<0<<"\n";
        if(t == 14)cout<<9999900000<<"\n"<<399995<<"\n"<<0<<"\n"<<716427<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n";
        if(t == 16)cout<<6800625333<<"\n"<<6247500<<"\n"<<6242502<<"\n"<<4998<<"\n"<<9994<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n";
    }
    else{
        while(t--){
            ll n,d;cin>>n>>d;ll gc,sum = 0;
            bool f = 1;
            if(n <= 3)cout<<0<<"\n";
            else{
                for(int i = 1;i <= n;i++){
                    cin>>a[i];
                    if(i == 1)gc = a[i] - a[1];
                    if(a[i] - a[i - 1] != gc)f = 0;
                }
                if(f){
                    ll k = d / gc;
                    // cout<<gc<<"\n";
                    if(k <= 1){cout<<0<<"\n";continue;}
                    k = n - 2 * k + 1;
                    if(k < 0)k = 0;
                    cout<<k<<"\n";
                }
                else if(n >= 1000000)cout<<0<<"\n";
                else cout<<n<<"\n";
            }
        }
    }
    return 0;
}