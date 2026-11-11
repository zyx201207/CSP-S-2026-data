#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
int ans;
long long num(long long x){
    long long sum=0;
    for(int i=1;i<=x;i++){
        sum+=a[i];
    }
    return sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=a[i]-b[i-1];
    }
    for(int i=2;i<=n;i++){
        if(num(i)+m>=a[i]*i){
            ans=max(ans,i);
        }
    }
    cout<<ans;
    return 0;
}
