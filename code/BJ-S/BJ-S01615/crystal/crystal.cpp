#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500001],b[500001];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,sum=99999999;
        while(l<=r){
            int mid=(l+r)/2;
            if((i-mid+1)*a[i]-b[i]+b[mid-1]<=m){
                sum=min(sum,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-sum+1);
    }
    cout<<ans<<endl;
    int Oct31=0,Dec25=0,t=1000000;
    if( Oct31==Dec25? 0:0){
        while(t--)cerr<<"RP++";
    }
    return 0;
}
