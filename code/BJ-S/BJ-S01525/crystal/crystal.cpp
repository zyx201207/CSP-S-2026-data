#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
long long a[N],s[N],m,res=1;
long long bs(int i){
    long long l=1,r=i-res+1,mid,ans=i;
    while(l<=r){
        mid=(l+r)/2;
        if((s[i]-s[mid-1])+m>=(i-mid+1)*a[i]){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return i-ans+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=n;i>res;i--){
        long long t=bs(i);
        if(t>res)res=t;
    }
    cout<<res;
    return 0;
}
