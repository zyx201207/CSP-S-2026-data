#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
bool check(int l){
    long long p=l;
    for(int i=l;i<=n;i++){
        if(a[i]*p-(sum[i]-sum[i-l])<=m){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
