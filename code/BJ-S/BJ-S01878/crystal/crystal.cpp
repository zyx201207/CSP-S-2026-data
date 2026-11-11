#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long ans[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long l=0;
    long long sum=0;
    for(long long r=0;r<n;r++){
        if(r>0){
            sum+=(a[r]-a[r-1])*r;
        }
        while(sum>m){
            l++;
            sum-=(a[r]-a[l]);
        }
        ans[r]=r-l+1;
    }
     long long maxn=0;
    for(long long i=0;i<n;i++){
        maxn=max(maxn,ans[i]);
    }
    cout<<maxn;
    return 0;
}
