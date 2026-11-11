#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,a[maxn];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout<<ans<<endl;
        return 0;
    }
    if(m==1){
        int maxa=0;
        for(int i=1;i<=n;i++) maxa=max(maxa,a[i]);
        cout<<maxa<<endl;
        return 0;
    }

    return 0;
}
