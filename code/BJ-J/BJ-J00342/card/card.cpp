#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    for(long long t=1;t<=n;t++){
        long long k[500005];
        for(long long j=t;j<=n;j++){
            k[j]=a[j];
            for(long long i=t;i<=j-1;i++){
                if(k[i]==k[j])for(long long h=i+1;h<=j;h++)k[h]=0;
            }
        }
        for(long long l=t;l<=n;l++)if(k[l]!=0)ans[k[l]]++;
    }
    sort(a+1,a+1+n);
    for(long long i=1;i<=n;i++){
        if(ans[a[i]]!=-1){
            cout<<ans[a[i]]<<" ";
            ans[a[i]]=-1;
        }
    }
    return 0;
}
