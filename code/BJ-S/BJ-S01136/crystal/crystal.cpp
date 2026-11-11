#include<bits/stdc++.h>
#define _for(i,x,y) for(int i=x;i<=y;++i)
#define _rep(i,x,y) for(int i=x;i<y;++i)
#define _forp(i,x,y,z) for(int i=x;i<=y;i+=z)
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N],s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    _for(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    _for(i,1,n) s[i]=s[i-1]+a[i];
    int ans=0;
    _for(i,1,n){
        int L=1,R=i,res=i;
        while(L<=R){
            int mid=L+R>>1;
            int val=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
            if(val<=m) R=mid-1,res=mid;
            else L=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans;
    return 0;
}
