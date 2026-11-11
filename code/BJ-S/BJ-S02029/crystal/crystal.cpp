#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    long long l=1,r=1;
    while(r<=n){
        if((r-l)*a[r]-(s[r-1]-s[l-1])<=m){
            ans=max(ans,r-l+1);
            r++;
        }else{
            l++;
        }
    }
    cout<<ans;
    return 0;
}
