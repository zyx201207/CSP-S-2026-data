#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
long long a[5000010];
bool check(long long x){
    long long cnt=0;
    for(int i=0;i<x-1;i++){
        cnt+=a[x-1]-a[i];
    }
    int i;
    for(i=1;i<=n-x+1;i++){
        cnt+=(a[i+x-1]-a[i+x-2])*(x-1);
        cnt-=a[i+1]-a[i-1];
        if(cnt<=m){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long left=1,right=n;
    while(left<=right){
        long long mid=left+(right-left)/2;
        if(check(mid)){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
