#include<bits/stdc++.h>
using namespace std;
long long a[500005], sum[500005], sum1[500005], sum2[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    for(long long i=1;i<=n;i++){
        if(i==n){
            sum[i]=0;
        }
        else sum[i]=a[i+1]-a[i];
        sum1[i]=sum1[i-1]+sum[i];
        sum2[i]=sum2[i-1]+sum1[i];
    }
    long long l=1, r=2, ans=1;
    while(l<=n){
        if(l<2){
            if((r-l)*sum1[r-1]-sum2[r-2]<=m){
                ans=max(ans, r-l+1);
                if(r<n)r++;
                else if(r>=n) l++;
            }
            else l++;
        }
        else {
            if((r-l)*sum1[r-1]-sum2[r-2]+sum2[l-2]<=m){
                ans=max(ans, r-l+1);
                if(r<n)r++;
                else if(r>=n) l++;
            }
            else l++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
