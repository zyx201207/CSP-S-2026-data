#include<bits/stdc++.h>
using namespace std;
long long a[100000005],cnt[100000005];
string c[100005],s[1000005];
int main(){
    freopen("travel.cpp.in","r",stdin);
    freopen("travel.cpp.out","w",stdout);
    long long n,cnt1=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>a[i]>>c[i];
       cnt1+=a[i];
    }
    for(int i=1;i<=n;i++){
        cnt[i]+=a[i]+a[i-1];
    }
    for(int i=1;i<=n;i++){
       for(int j=cnt[i-1]+1;j<=cnt[i];j++){
            s[j]=c[i];
       }
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=cnt1;j++){
            s[cnt1]=c[n];
       }
    }
    for(int j=0;j<cnt1;j++){
        if(s[j]!=s[cnt1-j]) ans++;
    }
    cout<<ans/2;
    return 0;
}
