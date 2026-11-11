#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int ans;
const int N=2e5+7;
int a[N];
int b[N];

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int k=30;k>=0;k--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]&(1<<k)){
                cnt++;
                b[cnt]=a[i];
            }
        }
        if(cnt>=m){
            for(int i=1;i<=cnt;i++)a[i]=b[i];
            n=cnt;
            ans+=(1<<k);
        }
    }
    cout<<ans<<endl;
    return 0;
}
