#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,ans=1;
bool check(long long l){
    long long k=0,zb=a[l],sum=0;
    for(long long i=l;i>=1;i--){
        k+=zb-a[i];
		   //cout<<sum<<" "<<k<<endl;
        if(m<k)break;
        sum++;
    }

    if(ans>sum)return false;
    else{
       ans=sum;
		return true;
    }
}
int erf(int l,int r){
    while(l<=r){
        long long mid=(l+r+1)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }

    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    erf(1,n);
    cout<<ans;
    return 0;
}
