#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,mm;
long long mx=0,mn=1e9+1;
long long a[500005],b[500005],cnt[500005];
long long check(int it){
    long long x=0;
    for(int i=1;i<=n;i++){
        if((b[i]<it)&&(it-b[i]<=mm)){
            mm-=it-b[i];
            b[i]=it;
            cnt[b[i]]++;
        }
        else if(b[i]==it){
            cnt[b[i]]++;
        }
        if(x<cnt[b[i]]){
            x=cnt[b[i]];
        }
    }
    memset(cnt,0,500005);
    return x;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    mm=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(mn==mx){
            ans=n;
            break;
        }
        else{
            for(int j=a[i];j<=mx;j++){
                long long k=check(j);
                ans=max(k,ans);
            }
        }
    }
    cout<<ans;
    return 0;
}
