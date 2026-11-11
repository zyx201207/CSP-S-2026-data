#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+50;
long long n,m;
long long a[N];
long long pre[N];
bool check(long long mid){
    for(long long i=1;i<=n-mid+1;i++){
        int j=i+mid-1;
        long long tmp=pre[j]-pre[i-1];
        long long val=a[j]*mid-tmp;
        // cerr<<val<<'\n';
        if(val<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    long long L=0,R=n,ans=0;
    while(L<=R){
        long long mid=(L+R)>>1;
        if(check(mid)){
            ans=mid;
            L=mid+1;
        }else{
            R=mid-1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
10 200
-154 -148 -55 -100 8 158 88 -134 114 55 
*/
