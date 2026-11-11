#include<bits/stdc++.h>
using namespace std;
const int N=2e5 + 7;
int n,m,a[N],b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        ++b[a[i]];
    }
    int ans=0;
    for(int i=1;i<=m;++i){
            ans+=b[i];
        cout<<ans<<' ';
    }
    return 0;
}