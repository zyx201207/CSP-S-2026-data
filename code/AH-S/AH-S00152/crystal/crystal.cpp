#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],maxn,sum,j=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        sum+=(i-j-1)*(a[i]-a[i-1]);
        while(sum>m) sum-=(a[i]-a[++j]);
        maxn=max(maxn,i-j);
    }
    cout<<maxn<<endl;
    return 0;
}
