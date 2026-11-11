#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ans=1;
    cin>>n>>m;
    long long a[n+10];
    long long sum=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    sum=(1+n)/2;
    long long l=sum,r=sum;
    while(abs(a[sum]-a[l-1])<=m||abs(a[sum]-a[r+1])<=m){
        if(abs(a[sum]-a[l-1])<=abs(a[r+1]-a[sum])){
            if(abs(a[sum]-a[l-1])<=m){
                l--;
                m-=abs(a[sum]-a[l]);
                ans++;
            }
        }
        if(abs(a[sum]-a[l-1])>abs(a[r+1]-a[sum])){
            if(abs(a[r+1]-a[sum])<=m){
                r++;
                m-=abs(a[r]-a[sum]);
                ans++;
            }
        }
        if(abs(a[sum]-a[l])>m&&abs(a[sum]-a[r])>m)break;
    }
    cout<<ans;
    return 0;
}