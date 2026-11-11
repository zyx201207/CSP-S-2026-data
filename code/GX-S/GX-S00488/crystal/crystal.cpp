#include<bits/stdc++.h>
using namespace std;
long long num[500005];
long long l=1,r=500005,mid,ans=1,n,m;
bool check(long long val){
    if(val>n) return false;
    long long t=0;
    long long ac=num[val];
    for(int i=1;i<=val;i++){
        t+=(ac-num[i]);
        if(t>m) return false;
    }
    return true;

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+1+n);
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
