#include<bits/stdc++.h>
using namespace std;
const long long MX=2e5+2;
long long n,m,a[MX],sum=1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,greater<long long>());
    long long sum=a[0];
    for(long long i=1;i<m;i++){
        sum&=(a[i]);
    }
    cout<<sum;
    return 0;
}