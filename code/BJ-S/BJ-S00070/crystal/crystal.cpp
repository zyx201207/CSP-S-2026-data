#include<iostream>
#include<cstdio>
#include<algorithm>
#define endl '\n'
using namespace std;
using ll=long long;
int n,l=1,mx=1;
ll m,a[500005],sum;
int main(){
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>m and l<=i) sum-=a[i]-a[l++];
        mx=max(mx,i-l+1);
    }
    cout<<mx<<endl;
    return 0;
}