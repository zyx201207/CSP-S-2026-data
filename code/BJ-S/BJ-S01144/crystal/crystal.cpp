#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],d[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=1;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
        //cout<<d[i]<<" ";
    }//cout<<endl;
    long long j=1,i=1,add=0;
    while(i<=n){
        if(add+(j-1)*d[i]<=m){
            add+=(j-1)*d[i];
            ans=max(ans,j);
            j++;
        }
        else{
            while(add+(j-1)*d[i]>m){
                if(add-sum[i-1]+sum[i-(j-1)-1]<0){
                    add=0;
                    j=1;
                    break;
                }
                add-=(sum[i-1]-sum[i-(j-1)-1]);
                j--;
            }
            add+=(j-1)*d[i];
            ans=max(ans,j);
            j++;
        }
        i++;
        //cout<<add<<" "<<j<<" "<<ans<<endl;
    }
    //ans=max(ans,j);
    cout<<ans<<endl;
    return 0;
}
