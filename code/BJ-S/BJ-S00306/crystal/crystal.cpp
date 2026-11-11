#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
long long n,m,ans=0;
bool c(long long x){
    long long ans1=0,m2=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]<=x){
            m2+=x-a[i];
            if(m2>m){
                if(ans1>ans){
                    ans=ans1;
                    return 1;
                }
                return 0;
            }else{
                ans1++;
            }
        }
    }
    if(ans1>ans){
        ans=ans1;
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long l=a[0],r=a[n-1];
    while(l<=r){
        long long m1=(l+r)/2;
        if(c(m1)){
            r=m1-1;
        }else{
            l=m1+1;
        }
    }
    cout<<ans;
    return 0;
}
