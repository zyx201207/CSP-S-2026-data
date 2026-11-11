#include <bits/stdc++.h>
using namespace std;
const int N=5.1e5;
long long n,m,a[N],ma=INT_MIN;
int cmp(long long x,long long y){
    return x>y;
}
long long check(long long x){
    long long c=0;
    long long sum=m;
    for(int i=1;i<=n;i++){
        if(x>=a[i]&&sum-(x-a[i])>=0){
            c++;
            sum=sum-(x-a[i]);
        }
    }
    return c;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long l=1,r=n;
    while(l<r){
        long long mid=(l+r)>>1;
        if(check(a[mid])>=ma){
            ma=check(a[mid]);
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ma<<endl;
    return 0;
}
