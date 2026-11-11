//GZ-J00082 陈雨晴
#include <bits/stdc++.h>
using namespace std;
long long d[10000005];
bool cmp(long long a,long long b){
    return a>=b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>d[i];
    }
    sort(d+1,d+n+1,cmp);
    long long maxn=0;
    for(long long j=1;j<=n;j++){
    long long ans=d[j];
    for(long long i=j+1;i<=m;i++){
        ans&=d[i];
    }maxn=max(maxn,ans);
    }
cout<<maxn;
    return 0;
}
