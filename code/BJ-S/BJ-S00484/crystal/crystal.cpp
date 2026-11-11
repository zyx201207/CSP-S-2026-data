#include<bits/stdc++.h>
using namespace std;
const int N=5e5 + 7;
int a[N],n,m,b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        b[i]=a[i]-a[i-1];
    }
    int l=1,ans=1,sum=0;
    for(int r=2;r<=n;++r){
        sum+=(r-l)*b[r];
        while(sum>m){
            sum-=(a[r]-a[l]);
            ++l;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}