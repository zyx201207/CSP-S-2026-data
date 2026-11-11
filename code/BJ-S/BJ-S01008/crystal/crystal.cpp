#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[5000001],b[5000001];
long long cnt=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
    long long sum=0;
    for (int i=1;i<=n;i++){
        if (i<2)continue;
        if (sum+1ll*(i-1)*b[i]<=m){
            sum+=1ll*(i-1)*b[i];
        }else{
            ans=i-1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
