#include<bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;
int a[N];
int sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int j=1;
    int mmax=0;
    for(int i=1;i<=n;i++){
        while((i-j+1)*a[i]-(sum[i]-sum[j-1])>m)j++;
        mmax=max(mmax,i-j+1);
    }
    cout<<mmax<<endl;
    return 0;
}
