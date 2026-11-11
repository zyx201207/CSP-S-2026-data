#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n],sum[n];
    char b[n];
    for(long long i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum[i]=1;
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]==b[j])sum[i]++;
        }
        ans+=a[i];
    }
    for(int i=0;i<n;i++){
        if(sum[i]==n)cout<<"0";
        return 0;
    }
    if(ans%2==0){
        cout<<ans/2;
    }else{
        cout<<(ans-1)/2;
    }
    return 0;
}