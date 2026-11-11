# include <bits/stdc++.h>
using namespace std;
#define ll long long
const int CLS=5e5+10;
int n,a[CLS],ans;
ll pre[CLS],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++) pre[i]=pre[i-1]+a[i];
    for(int i=2; i<=n; i++){
        int l=1,r=i-1,best=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if((1ll*a[i]*(i-mid)-(pre[i-1]-pre[mid-1]))>m) l=mid+1;
            else                                           r=mid-1,best=min(best,mid);
        }
        ans=max(ans,i-best+1);
    }
    cout<<ans;
    return 0;
}
//5 5
//1 2 4 8 9
