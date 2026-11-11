#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],s[N];
int ans;
int f1(int x,int y){
    return a[x]*y-s[x-1]+s[x-1-y];
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)/2+1;
            if(f1(i,mid)<=m){
                l=mid;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,l+1);
    }
    cout<<ans<<endl;
    return 0;
}
