#include<bits/stdc++.h>
using namespace std;
long long a[50001000],b[50001000],s[50001000];
long long ans=0,n,m;
void ff1(){
    sort(a,a+n);
    for(long long i=1;i<n;i++){
        b[i-1] = a[i]-a[i-1];
    }
    for(long long i=0;i<n;i++){
        long long num =b[i];
        if(s[a[i]]==0){
            s[a[i]]=1;
        for(long long j=i+1;j<n;j++){
            long long aNum = j-i+1;
            num = num+aNum*b[j];
            if(num<=m) ans=max(ans,aNum);
            if(num>m) break;
        }
        }
    }
    cout<<ans+1;
}
void ff2(){
    for(long long i=0;i<n;i++){
        long long h=0;
        if(s[a[i]]==0){
            s[a[i]]=1;
            for(long long j=1;j<=n;j++){
            long long uh = a[i]-a[j-1];
            if(a[i]>=a[j-1]&&h+uh<=m){
                h=uh+h;
                b[j]=b[j-1]+1;
                ans=max(b[j],ans);
            }else{
                b[j]=b[j-1];
                h=max(uh,h);
            }
        }
        }
    }
    cout<<ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++) cin>>a[i];
    ff2();
    return 0;
}
