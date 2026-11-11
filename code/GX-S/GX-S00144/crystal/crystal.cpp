#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m;
long long a[N];
long long dis[N];
long long pre[N];
long long ans;

long long check(long long k){
    long long sum=0,num=m;
    for(int j=k-1;j>=1;j--){
        if(num>=a[k]-a[j]) sum++,num-=a[k]-a[j];
        else break;
    }
    if(sum) sum++;
    return sum;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==1){cout<<0; return 0;}
    long long l=1,r=n;
    while(l<=r){
        long long mid=(l+r)/2;
        long long kkk=check(mid);
        ans=max(ans,kkk);
        if(kkk>=mid) l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<"\n";
    return 0;
}
