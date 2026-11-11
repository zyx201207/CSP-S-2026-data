#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];

    }
    long long ans=0;
    for(long long i=1;i<=n;i++){
            long long h=a[i]*i;
        if(h-s[i-1]<=m) ans=max(ans,i);
        else{

            long long l=0,r=i-1;
            while(l<r){
                long long mid=(l+r)/2;
                long long j=a[i]*(i-1-mid)-(s[i-1]-s[mid]);
                if(j<=m){
                    r=mid;
                    ans=max(ans,i-mid);
                }
                else{
                    l=mid+1;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}



