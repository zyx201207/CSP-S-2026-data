#include<bits/stdc++.h>
using namespace std;
    int n,m,a;
    int ans=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        ans=max(ans,a);
    }
    cout<<ans;
return 0;
}
