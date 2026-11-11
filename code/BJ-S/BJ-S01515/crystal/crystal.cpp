#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;long long m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int l=1,r=1;
    long long m1=0;
    int ans=0;
    while(r<=n){
        if(m1<=m&&r<=n){
            ans=max(ans,r-l+1);
            r++;
            m1+=(a[r]-a[r-1])*(r-l);
        }else if(m1>m){
            m1-=a[r]-a[l];
            l++;
            ans=max(ans,r-l+1);
        }
    }cout<<ans;
    return 0;
}
