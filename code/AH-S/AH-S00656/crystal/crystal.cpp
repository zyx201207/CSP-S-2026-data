#include<bits/stdc++.h>
using namespace std;//22.54
long long a[2100000],b[2100000],n,m;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long cnt=0,k=1;
    for(int i=2;i<=n;i++){
            cnt+=k*(a[i]-a[i-1]);
            k++;
            b[i]=cnt;
    }
    long long maxn=1;
    for(long long i=1;i<=n;i++){
        for(long long j=i+maxn;j<=n;j++){
            if(b[j]-b[i]-(i-1)*(a[j]-a[i])<=m){
                maxn=max(maxn,j-i+1);
                //cout<<i<<" "<<j<<" "<<b[j]<<" "<<b[i]<<" "<<(i-1)*(a[j]-a[i])<<endl;
            }else{
            break;
            }
        }
    }
    cout<<maxn;
    return 0;
}

