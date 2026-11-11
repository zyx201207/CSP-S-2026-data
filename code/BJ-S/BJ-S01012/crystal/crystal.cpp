#include<bits/stdc++.h>
#define int long long
#define fr(i,l,r) for(int (i)=(l);(i)<=(r);i++)
#define fd(i,r,l) for(int (i)=(r);(i)>=(l);i--)
using namespace std;

const int N=5e5+10;
int a[N],b[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    fr(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    int res=0;
    fr(i,1,n){
        b[i]=b[i-1]+a[i];
        int l=0,r=i-2,ans=i;
        while(l<=r){
            int mid=(l+r)/2;
            bool ok=((i-1-mid)*a[i]-(b[i-1]-b[mid])<=m);
            if(ok)ans=mid,r=mid-1;
            else l=mid+1;
        }
        res=max(res,i-ans);
    }
    cout<<res<<'\n';
    return 0;    
}