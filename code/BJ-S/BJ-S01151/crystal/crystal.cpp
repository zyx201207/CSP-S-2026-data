#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long hzh[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    hzh[0]=0;
    for(long long i=1;i<=n;i++){
        hzh[i]=a[n]-a[i]+hzh[i-1];
    }
    long long maxz=0;
    for(long long i=1;i<=n;i++){
        if(hzh[i-1]-(a[n]-a[i])*(i-1ll)<=m){
            if(i>=maxz){
                maxz=i;
            }
        }
    }
    cout<<maxz;
    return 0;
}
