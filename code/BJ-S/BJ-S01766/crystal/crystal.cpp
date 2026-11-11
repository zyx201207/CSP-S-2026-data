#include<bits/stdc++.h>
using namespace std;
namespace Mortis{
using ll=long long;
ll a[500001];
void main(){
    int n;ll m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    int res=0;
    for(int i=1,j=1;i<=n;++i){
        m-=ll(i-j)*(a[i]-a[i-1]);
        for(;m<0;m+=a[i]-a[j++]);
        res=max(res,i-j+1);
    }cout<<res<<'\n';
}
}
int main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    Mortis::main();
    return 0;
}