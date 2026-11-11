#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[200009],s[109],d[200009];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=30;i>=0;i--){
        long long cnt=0;
        for(long long j=1;j<=n;j++){
            if(d[j]==0 && ((a[j]&(1ll<<i))>>i)==1) cnt+=1;
        }
        if(cnt>=m){
            ans+=(1ll<<i);
            for(long long j=1;j<=n;j++){
                if(d[j]==0 && ((a[j]&(1ll<<i))>>i)==0) d[j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
