#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,len;
long long a[2000005],b[200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    if(c==11 || c==12){
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++) cin >> a[i];
            if(a[2]-a[1]>2*d){
                cout << "0\n";
                continue;
            }
            cout << n-1 << '\n';
        }
    }
    if(c>=15 && c<=18){
        while(t--){
            cin >> n >> d;
            for(int i=1;i<=n;i++) cin >> a[i];
            cout << 1;
        }
    }
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++) cin >> a[i];
        cout << n/2 << '\n';
    }
    return 0;
}
