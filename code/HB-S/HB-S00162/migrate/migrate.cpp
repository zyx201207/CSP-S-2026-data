#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int x[maxn];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,d;
    int c,t;
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        if(n==1||n==2){
            cout << 0 << "\n";
            continue;
        }
        int z;
        cin >> x[1] >> x[2];
        z=x[2]-x[1];
        bool f=true;
        for(int i=3;i<=n;i++){
            cin >> x[i];
            if((x[i]-x[i-1])!=z) f=false;
        }
        int ans=0;
        if(f){
            if(3*z>d&&2*z<d) ans=n-3;
        }
        else{
            for(int i=1;i<=n;i++){
                bool f=false;
                int l=i;
                int cnt=0;
                while(l<=n){
                    l++;
                    if((x[l]-x[i]>d)&&x[l]-x[i]<2*d){
                        ans++;
                    }
                    else break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
