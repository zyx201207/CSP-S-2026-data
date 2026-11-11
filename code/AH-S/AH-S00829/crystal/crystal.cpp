#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    s[1]=0;
    long long ans=1;
    for(long long i=1;i<=n;i++){
        for(long long j=i+ans;j<=n;j++){
            if(i==1) s[j]=(j-1)*(a[j]-a[j-1])+s[j-1];
            long long w=(s[j]-s[i])-(a[j]-a[i])*(i-1);
            if(w<=m) ans=max(ans,j-i+1);
            else if(i!=1) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
