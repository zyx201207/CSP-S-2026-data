#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],simi[500005],maxn=1,low=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        simi[i]=simi[i-1]+a[i];
    }
    for(long long i=1;i<=n;i++){
        for(long long j=low;j<i;j++){
            long long sum=(i-j)*a[i];
            if(sum-(simi[i-1]-simi[j-1])<=m){
                maxn=max(maxn,i-j+1);
            }
            else{
                low=max(low,j)+1;
           }
        }
    }
    cout<<maxn<<"\n";
    return 0;
}
