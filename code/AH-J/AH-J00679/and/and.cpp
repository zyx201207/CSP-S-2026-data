#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2E5+10;
LL n,m;
LL a[N];
bool cmp(const LL &x,const LL &y){
    return x>y;
}
bool f[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    LL maxn=a[1];
    for(LL i=1;i<=m-1;i++){
        LL k=0;
        for(LL j=2;j<=n;j++){
            if((maxn&a[j]>=k)&&(f[j]==0)){
                k=maxn&a[j];
                f[j]=1;
            }
        }
        maxn=k;
    }
    cout<<maxn;
    return 0;
}
