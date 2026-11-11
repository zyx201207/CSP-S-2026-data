#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,lb,rb,rs,a[500001],pr[500001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++) {
        pr[i]=pr[i-1]+a[i];
        lb=1;
        rb=i;
        while(lb<rb) {
            long long md=(lb+rb)/2;
            if(m>=a[i]*(i-md+1)-pr[i]+pr[md-1]) rb=md;
            else lb=md+1;
        }
        rs=max(rs,i-lb+1);
    }
    cout<<rs<<"\n";
    return 0;
}
