#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000005;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        int a[N],b[N];
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            if(i>1){
                b[i-1] = a[i]-a[i-1];
            }
        }
        int dis = b[1];

        if(d<2*dis) {
            cout<<0<<endl;
            continue;
        }
        if(d>n&&d>2*dis) {
            cout<<0<<endl;
            continue;
        }
        cout<<n-3<<endl;
    }
    return 0;
}
