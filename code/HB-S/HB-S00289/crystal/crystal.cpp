#include <bits/stdc++.h>

using namespace std;
long long n,m;
vector<long long> v;
vector<long long> sum;
bool check(long long len){
    for(long long i=len;i<=n;i++){
        long long t=(len-1)*v[i]-sum[i-1];
        if(m>=t){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    v.resize(n+1);
    sum.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.end());
    for(int i=1;i<=n;i++)sum[i]=v[i]+sum[i-1];
    long long l=0,r=n;
    while(l<=r){
        long long mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l-1;
}
