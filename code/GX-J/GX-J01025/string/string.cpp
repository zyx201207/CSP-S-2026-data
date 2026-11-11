#include<bits/stdc++.h>
using namespace std;
long long a[20900009];string s[20900009],s1[20009009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,ans=0,k=0,yi=1;cin>>n;
    for(long i=1;i<=n;i++){
       cin>>a[i]>>s[i];
       sum+=a[i];
    }
    for(long i=1;i<=n;i++){
        for(long j=1;j<=26;j++){
            if(s[i]!=s[j]) yi++;
        }
    }
    if(n==2&&yi==2) cout<<min(a[1],a[2]);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=a[i];j++){k++;s1[k]=s[i];}
    }
    for(long i=1;i<=sum;i++){
        if(s1[i]!=s1[sum-i+1]){
            s1[sum-i+1]=s1[i];
            ans++;

        }
    }
    cout<<ans;
    return 0;
}
