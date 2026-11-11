#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long l,r,mid,sum;
bool check(long long num){
    sum=0;
    for(int i=1;i<num;i++){
        sum+=a[i];
    }
    for(int i=0;i<=n-num;i++){
        sum=sum-a[i]+a[i+num];
        if(a[i+num]*num-sum<=m){
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
    l=1,r=n;
    sort(a+1,a+n+1);
    while(l<r){
        mid=(l+r+1)/2;
        // cout<<l<<" "<<r<<" "<<mid<<" ";
        if(check(mid)){
            l=mid;
            // cout<<"YES";
        }else{
            r=mid-1;
            // cout<<"NO";
        }
        // cout<<endl;
    }
    cout<<l<<endl;
    return 0;
}
