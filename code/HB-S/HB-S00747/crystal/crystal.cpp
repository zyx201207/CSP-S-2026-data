#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+3;
int s[N],n,m,a[N],ans=0,as=0;bool lf=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    stable_sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1ll]+(i-1ll)*(a[i]-a[i-1ll]);
    }
    int l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)>>1;as=1;lf=0;
        for(int i=1;i+mid-1<=n;i++){
            as=i+mid-1;
            //cout<<as<<" "<<i<<" "<<mid<<" "<<s[i]-s[as]-((a[i]-a[as])*(as-1))<<"\n";
            if(s[as]-s[i]-((a[as]-a[i])*(i-1))<=m){
                lf=1;ans=mid;break;
            }
        }
        if(lf){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
