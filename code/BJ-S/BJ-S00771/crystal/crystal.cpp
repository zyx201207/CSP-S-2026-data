#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N];
long long res;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<long long>());
    long long l=1,r=1;
    long long sum=0;
    while(l<=n){
        while(r<n&&sum+a[l]-a[r+1]<=m){
            sum+=(a[l]-a[r+1]);
            ++r;
        }
        res=max(res,r-l+1);
        sum-=(a[l]-a[l+1])*(r-l+1);
        ++l;
        if(r==n){
            break;
        }
    }
    cout<<res;

    return 0;
}
