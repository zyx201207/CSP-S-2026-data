#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1;
    int r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(mid<m){
            l=mid+1;
        }
        if(mid>m){
            r=mid-1;
        }
        if(mid=m){
            int ans=mid;
            r=mid-1;
        }
    }
    cout<<a[n];
    return 0;
}
