#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m;
long long a[N];

bool check(long long x){
    long long sum=0;
    for(int i=1;i<=x;i++){
        sum+=a[x]-a[i];
        if(sum>m){
            //cout<<x<<" "<<a[x]<<" "<<sum<<" "<<m<<"\n";
            return 0;
        }
    }
    //cout<<x<<" "<<a[x]<<" "<<sum<<" "<<m<<"\n";
    return 1;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    //cout<<check(315275)<<"\n";
    long long l=1,r=n;
    long long mid=(l+r)>>1;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid))
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<r;
}
