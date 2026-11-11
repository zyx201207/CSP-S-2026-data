#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long m;
int dfa;
long long a[2000010];
int t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> dfa >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        long long d=a[2]-a[1];
        if(a[2]-a[1]!=a[n]-a[n-1]){
            cout << 0 << endl;
        }
        //cout << d << ' ' << n  << ' ' << a[1] << ' ' << m << ' ' << m/d << ' ' << m/d*2 << endl;
        unsigned long long ans=0;
        if(m/d<=(n-1)/2+1&&m/d>1){
            if(n>=m/d*2){
                ans+=n-m/d*2+1;
            }
        }
        cout << ans;
        puts("");

    }
    return 0;
}
