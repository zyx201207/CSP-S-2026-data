#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        if(m<(i-1)*(a[i]-a[i-1])){
            cout<<i-1;
            return 0;
        }else m-=(i-1)*(a[i]-a[i-1]);
    }
    cout<<n;
    return 0;
}
