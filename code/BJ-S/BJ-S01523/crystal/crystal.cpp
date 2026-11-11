#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int a[N],b[N],c[N],d[N],sum,num,ans,noww;
int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","r",stdout);
    int n,m,real_m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];sum+=a[i];
    }sum/=n;
    for(int i=1;i<=n;i++){
        b[i]=max(a[i],sum)-min(a[i],sum);
        d[i]=b[i];
        if(a[i]>sum)c[i]=1;
    }sort(d+2,d+n+2);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[j]+num<=real_m){
                noww++;
            }
        }noww=0;
        if(noww>ans)ans=noww;
    }cout<<ans;
}