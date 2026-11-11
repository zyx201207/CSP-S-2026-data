#include<iostream>
#include<algorithm>
using namespace std;

const long long N=5e5+5;
long long n,m;
long long a[N];
long long ans=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+1+n);
    long long L=1,sum=0;
    for(long long R=2;R<=n;++R){
        sum+=(R-L)*(a[R]-a[R-1]);//xindajia
        while(sum>m&&L<R)sum-=a[R]-a[L],++L;
        ans=max(ans,R-L+1);
    }
    cout<<ans<<"\n";
    return 0;
}