#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x[500005],ans=0,sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(m==0){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        long long minx=1e12,mini=-1;
        for(int j=1;j<=n;j++){
            if(x[j]<minx){
                minx=x[j];
                mini=j;
            }
        }
        a[i]=minx;
        x[mini]=1e12;
    }
    for(int i=1;i<=n-1;i++){
        sum[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n-1;i++){
        for(long long j=n-1;j>=1;j--){
            long long add=0;
            for(int k=i;k<=j;k++){
                add+=sum[k];
            }
            if(add<=m){
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans+1;
    return 0;
}
