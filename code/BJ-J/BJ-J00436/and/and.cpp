#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=29;j>=0;j--){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if((a[i]&ans)==ans && (a[i]&(1<<j))) cnt++;
        }
        if(cnt>=m) ans|=(1<<j);
    }
    cout<<ans;
    return 0;
}
