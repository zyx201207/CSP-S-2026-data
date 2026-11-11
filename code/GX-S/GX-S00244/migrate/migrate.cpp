#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        long long n,d;
        int ans=0;
        cin >> n >> d;
        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];
        if(d!=2){
            cout << 0 << endl;
            continue;
        }
        for(int i=1;i<=n-1;i++){
            int sum=0;
            for(int j=i+1;j<=n;j++){
                if(a[i]+d>=a[j]) continue;
                else if(a[i]+d+d<=a[j]) continue;
                else if(a[i]+d<a[j]&&i+1==j) break;
                sum++;
            }
            if(sum==1) ans++;
        }
        cout << ans <<endl;
    }
    return 0;
}
