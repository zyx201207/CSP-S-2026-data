#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[500010],sa[500010],aim,ans,sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k>1e8){
        for(int i=1;i<=n;i++){
            sa[i]=sa[i-1]+a[i];
        }
        for(long long i=1;i<=n;i++){
            sum=i*a[i]-sa[i];
            if(sum<=k)aim=max(aim,i);
        }
        cout<<aim<<endl;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1]+a[i];
    }
    for(long long i=0;i<=n-2;i++){
        for(long long j=n;j>=i+2;j--){
            sum=(j-i)*a[j]-sa[j]+sa[i];
            if(sum>k)continue;
            if(sum<=k)ans=max(ans,j-i);
        }
    }
    if(ans==0)cout<<1;
    else cout<<ans<<endl;
    return 0;
}
