#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int a,b,c,d,e,ans;
    cin>>e;
    for(int i=1;i<=b;i++){
        cin>>d;
        ans+=d;
    }
    for(int i=1;i<=e;i++){
        cout<<ans<<endl;
    }
    return 0;
}
