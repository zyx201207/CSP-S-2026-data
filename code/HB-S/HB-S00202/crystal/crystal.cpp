#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define LL long long
LL n,m,a[500005],s[500005];
bool check(LL len){
    for(int i=1;i+len-1<=n;i++){
        int l=i,r=i+len-1;
        LL c=len*a[r]-(s[r]-s[l-1]);
        //cout<<l<<' '<<r<<' '<<c<<' '<<'\n';
        if(c<=m)return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=0,r=500000,ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
