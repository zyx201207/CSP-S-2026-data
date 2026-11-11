#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,max=LONG_MIN;
    cin>>n>>m;
    long long a[n],sum[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])sum[i]++;
        }
    }
    for(int i=0;i<n;i++){
        if(max<sum[i])max=sum[i];
    }
    long long ans;
    if(n%2==0){
        ans=n/2+max;
    }else{
        ans=(n-1)/2+max;
    }
    cout<<ans;
    return 0;
}