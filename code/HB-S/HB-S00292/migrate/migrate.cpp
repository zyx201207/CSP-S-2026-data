#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int r=0;r<t;r++){
        int n,d,a[2000005];
        cin >> n >> d;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        if(n<4){
            cout << 0;
            continue;
        }
        int ans = 0;
        for(int i=0;i<=n-4;i++){
            if(a[i+3]-a[i]==d+1){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
