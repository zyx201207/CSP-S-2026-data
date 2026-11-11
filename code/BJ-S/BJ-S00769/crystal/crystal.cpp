#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans=1;
long long a[500005];
long long l;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    l=1;
    for(int i=2;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>m&&l<i){
            sum-=(a[i]-a[l]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}

