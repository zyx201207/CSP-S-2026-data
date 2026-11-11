#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],ans,sum1,diff[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) diff[i-1]=a[i]-a[i-1];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+diff[i];
    long long l=1;
    for(int r=1;r<n;r++){
        long long len=r-l+1;
        sum1+=len*diff[r];
        if(sum1>m){
            while(sum1>m){
                sum1-=sum[r]-sum[l-1];
                l++;
                len--;
                //cout<<endl<<"now we come to "<<l<<":"<<r<<endl<<"now sum="<<sum1;
            }
        }
        ans=max(ans,r-l+1);
        //cout<<endl<<"now the ans is "<<ans;
    }
    //cout<<endl<<ans+1;
    cout<<ans+1;
}