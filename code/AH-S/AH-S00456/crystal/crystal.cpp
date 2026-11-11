#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],sum[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll l=1,maxn=1,sum=0;
    for(int r=1;r<=n;r++){
        sum+=(a[r]-a[r-1])*(r-l);
        while(sum>m&&l<=r){
            sum-=a[r]-a[l];
            l++;
        }
        maxn=max(maxn,r-l);
    }
    cout<<maxn+1;
    return 0;
}
