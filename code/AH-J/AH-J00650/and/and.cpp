#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,maxn,a[202020];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==1){
        cout<<maxn;
    }else if(m==2){
        cout<<maxn;
    }
    return 0;
}
