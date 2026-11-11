#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(a[i],mx);
    }
    if(m==1)cout>>mx;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans=max(ans,a[i]&&a[j]);
        }
    }
    cout<<ans;
    return 0;
}
