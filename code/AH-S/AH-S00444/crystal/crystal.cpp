#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005],d[1000005],sum,maxn=-0x3f3f3f3f3f3f3f3f;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int l=1,r=1;
    while(l<=n){
        while(r<=n&&sum+(a[r]-a[r-1])*(r-l)<=m){
            sum=sum+(a[r]-a[r-1])*(r-l);
            r++;
        }
        //cout<<l<<" "<<r<<" "<<sum<<endl;
        maxn=max(maxn,r-l);
        sum-=((a[l+1]-a[l]))/(r-l);
        l++;
        //cout<<l<<" "<<r<<" "<<sum<<endl;
    }
    cout<<maxn;
    return 0;
}
