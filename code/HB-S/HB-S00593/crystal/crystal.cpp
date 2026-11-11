#include<bits/stdc++.h>
using namespace std;
long long a[500010]={0};
long long sum[500010]={0};
long long fin=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    }
      sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
  
    for(long long i=1;i<=n;i++){
        long long l=1,r=i;
        long long mid,ans=i;
        while(l<=r){
            mid=(l+r)/2;
            if(a[i]*(i-mid)-(sum[i-1]-sum[mid-1])<=m){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        fin=max(fin,i-ans+1);
    }
    cout<<fin;

    return 0;
}