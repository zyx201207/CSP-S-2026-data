#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,mx=-0x3f3f3f3f;
long long m,sum[500005],a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<r){
            mid=(l+r)/2;
            if((long long)(i-mid)*a[i]-(sum[i-1]-sum[mid-1])>m) l=mid+1;
            else r=mid;
        }
        mx=max(i-l+1,mx);
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
