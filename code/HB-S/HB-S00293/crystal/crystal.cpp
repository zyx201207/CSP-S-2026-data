#include<bits/stdc++.h>
using namespace std;
long long n,m,max1=0,ans=0,mm;
long long a[500001],b[500001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        ans=0,mm=m;
        for(long long j=1;j<=n;j++){
            if(a[i]>=a[j]){
                b[j]=a[i]-a[j];
            }else if(a[i]<a[j]){
                b[j]=a[j]-a[i];
            }
        }
        sort(b+1,b+n+1);
        for(long long j=1;j<=n;j++){
            if(mm<b[j]){
                break;
            }
            mm-=b[j];
            ans++;
        }
        max1=max(max1,ans);
    }
    cout<<max1;
    return 0;
}
