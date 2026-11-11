#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],add[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        add[i]=add[i-1]+a[i];
    }
    long long l=1,r=n;
    while(r>=l){
        long long mid=(r+l)/2;
        if(a[mid]*(mid-1)-add[mid-1]<=m){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
