#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m,sum=0;
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=a[n];
    for(int i=n;i>=n-m+1;i--) ans=(ans&a[i]);
    sort(a+1,a+n+1);
    int r=n,l=n-1;
    sum=a[r];
    while(l<=r&&l>=1){
        if(r-l==m){
            ans=max(ans,sum);
        }
        sum=(sum&a[l]);
        l--;
        if(r-l==m){
            ans=max(ans,sum);
        }
        if(sum<a[l+1]){
            sum=a[l+1];
            r=l+1;
        }
    }
    cout<<ans;
    return 0;
}
