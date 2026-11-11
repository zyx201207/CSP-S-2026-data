#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
long long n,m;
long long a[MAXN];
long long sum[MAXN];
long long f(long long x){
    return x*a[x]-sum[x];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    long long cnt=0;
    while(f(cnt)<=m){
        cnt++;
    }
    cout<<cnt-1<<endl;
    return 0;
}