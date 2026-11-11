#include<bits/stdc++.h>
using namespace std;
const long long N=2000090;
long long a[N],ans=0,sum,s2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-1;j++){
            sum=a[i+j]&a[i];
            ans=max(sum,ans);
        }
    }
    cout<<ans;
    return 0;
}
