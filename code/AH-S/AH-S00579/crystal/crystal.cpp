#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(long long i=2;i<=n;i++){
        s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=i-1,r=n+1;
        while(l+1<r){
            int mid=(l+r)/2;
            long long sum=s[mid]-s[i]-(i-1)*(a[mid]-a[i]);
            if(sum>m){
                r=mid;
            }else{
                l=mid;
            }
        }
        ans=max(ans,l-i+1);
    }
    cout<<ans;
    return 0;
}
