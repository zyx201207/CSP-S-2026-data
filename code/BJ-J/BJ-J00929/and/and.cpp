#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
priority_queue<ll> a;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int te;cin>>te;
        a.push(te);
    }
    ll ans=a.top();
    a.pop();
    for(int i=2;i<=m;i++){
        ans=ans&a.top();
        a.pop();
    }
    cout<<ans<<endl;
    return 0;
}
