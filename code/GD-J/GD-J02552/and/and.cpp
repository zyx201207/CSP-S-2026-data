#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
ll a[200005];
ll f[2005][2005];
ll maxn=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int t=1,t2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i-1)t=0;
    }
    if(t==1){
        maxn = a[n];
        for(int i=n-1;i>=n-m+1;i--)maxn&=a[i];
    cout<<maxn;
    return 0;
    }
    for(int i=1;i<=n;i++){f[i][1]=a[i];
        if(m==1)maxn = max(maxn,a[i]);}
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            f[i][j] = max(f[i-1][j],f[i-1][j-1]&a[i]);
        }
    }
    maxn = max(maxn,f[n][m]);
    cout<<maxn;
    return 0;
}
