#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n;long long m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());

    vector<int> sum(n+5,0);
    for(int i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i-1];
    }
    long long ans=0;
    for(int i=0;i<n;++i){
        long long l=0,r=i,mid;
        while(l<r){
            mid=l+r>>1;
            if(sum[i]-sum[mid]+m>=a[i]*(i-mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-mid);
    }
    cout<<ans+1;
}