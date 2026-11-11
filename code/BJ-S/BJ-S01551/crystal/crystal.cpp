#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ansans;
int a[500010],s[500010],sa[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n; i++){
        s[i]=s[i-1]+a[i];
        int l=1,r=i,ans;
        while(l<=r){
            int mid=l+r>>1;
            if((a[i]*(i-mid+1))-(s[i]-s[mid-1])<=m){
                ans=i-mid+1;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ansans=max(ans,ansans);
    }
    cout<<ansans<<endl;
    return 0;
}
//Oct31==Dec25?
