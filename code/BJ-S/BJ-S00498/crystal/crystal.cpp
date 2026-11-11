#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],maxx=-10000;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(long long i=1;i<=n;i++){
        long long l=1,r=i,mid=(l+r)/2;
        while(l!=r){
            if((a[i]*(i-mid+1)-(s[i]-s[mid-1]))<=m){
                r=mid;
                mid=(l+r)/2;
            }
            else{
                l=mid+1;
                mid=(l+r)/2;
            }
        }
        maxx=max(maxx,i-mid+1);
    }
    cout<<maxx;
    return 0;
}
