#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++){
        b[i]=b[i-1]+a[i];
    }
    int maxn=0;
    for(int i=1; i<=n; i++){
        int l=1,r=i;
        while(l<r){
            long long mid=(l+r)/2;
            if((i-mid+1)*a[i]-(b[i]-b[mid-1])<=m){
                r=mid;
            } else{
                l=mid+1;
            }
        }
        maxn=max(maxn,i-l+1);
    }
    cout<<maxn;
    return 0;
}