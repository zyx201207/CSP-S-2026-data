#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,mini,ans;
ll a[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll cnt=0;
        for(int i=1;i+2<=n;i++){
            int sum=0;
            for(int j=i+2;j<=n;j++){
                if(a[j]-a[i]<=d) continue;
                if(sum) break;
                if(a[j-1]-a[i]<=d&&a[j]-a[i+1]<=d&&j<4) sum++;
            }
            cnt+=sum;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

