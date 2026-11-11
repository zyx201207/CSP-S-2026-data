#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        bool a[n+1];
        for(int i=1;i<n;i++){
            int l,r;
            cin>>l>>r;
            a[l]=1;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                ans++;
            }
        }
        cout<<ans%n<<"\n";
    }
    return 0;
}