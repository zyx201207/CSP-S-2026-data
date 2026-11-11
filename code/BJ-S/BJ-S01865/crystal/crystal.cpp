#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[600001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=0,ans=0,j=n+1;
    for(long long i=n;i>=1;i--){
        if(j>i){
            sum=0;
            j=i;
        }else{
            sum+=(i-j+1)*(a[i]-a[i+1]);
        }
        while(j-1>=1&&sum+a[i]-a[j-1]<=m){
            j--;
            sum+=a[i]-a[j];
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}
