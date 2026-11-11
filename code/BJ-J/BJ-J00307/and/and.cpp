#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],n,k,sum;
void dfs(int x,int k,int f) {
    if(k<=0) {
        sum=max(sum,f);
        return ;
    }
    for(int i=x+1;i<=n;i++) dfs(i,k-1,(f&a[i]));
}
signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(k==n) {
        sum=2147483647;
        for(int i=1;i<=n;i++) sum&=a[i];
        cout<<sum;
        return 0;
    }
    else if(k==1) {
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=n;i++) dfs(i,k-1,a[i]);
    cout<<sum;
    return 0;
}
