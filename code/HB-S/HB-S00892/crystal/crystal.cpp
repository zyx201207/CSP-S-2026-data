#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define fi first
#define se second
#define loop(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rloop(i,a,b) for(int i=(a);(i)>=(b);(i)--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;

const int N=5e5+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int n;
ll m,a[N],sum[N];

/*
sort and qianzhuihe
choosing lian xu yi duan is better
for len erfen (O(log n)) jike
check:loop(i,len,n)a[i]*len<=m+sum[i]-sum[i-len] (O(n))
=> O(n log n)
*/

bool check(int len){
    loop(i,len,n)if(a[i]*len<=m+sum[i]-sum[i-len])return 1;
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    loop(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    loop(i,1,n)sum[i]=sum[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        // cout<<l<<' '<<r<<' '<<mid<<' '<<check(mid)<<'\n';
        if(check(mid))l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
    return 0;
}
// g++ crystal.cpp -o crystal -O2 -std=c++14 -static -Wall -Wextra