#include<bits/stdc++.h>
using namespace std;
long long n,m,b=0,c,need=0,ans=0;
vector<long long>a;
int dp(int d){
    b=0;
    for(long long i=d;i<n;i++){
        b=(a[i]-a[i-1])*(i-d+1)+b;
        if(b>m){
            b=i-d+1;
            return b;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        scanf("%lld",&c);
        a.push_back(c);
    }
    sort(a.begin(),a.begin()+a.size());
    for(long long i=1;i<n-1;i++){
        need=dp(i);
        ans=max(ans,need);
    }
    cout<<ans;
    return 0;
}
