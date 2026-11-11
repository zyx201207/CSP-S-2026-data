#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=1;
    long long t=0;
    while(r<=n){
        ans=max(ans,r-l+1);
        r++;
        long long sum=a[r]-a[r-1];
        t+=(r-l)*sum;
        while(t>m&&l<r){
            l++;
            t-=(a[r]-a[l-1]);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
