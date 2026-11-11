#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long m,n,a[N],sum,l,r,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    l=1,r=1,sum=0,ans=0;
    cin>>n>>m;
    sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
            r++;
        if(a[i]*(r-l+1)<=sum+m){
            ans=max(ans,r-l+1);
        }
        else{
            while(a[i]*(r-l+1)>sum+m){
                sum-=a[l];
                l++;
            }
        }
        sum+=a[i];
    }
    cout<<ans;
    return 0;
}
//Oct31==Dec25?
