#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,a[MAXN],pos[MAXN];
long long check(long long l,long long r){
    long long cnt=0;
    for(int i=l;i<r;i++){
        for(int j=i+1;j<r;j++){
            cnt+=pos[j]*(r-j);
        }
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m/n>=a[n]-a[1]){
        cout<<n;
        return 0;
    }
    pos[1]=0;
    for(int i=2;i<=n;i++){
        pos[i]=a[i]-a[i-1];
    }
    long long ans=1;
    for(long long i=2;i<=n;i++){
        for(long long j=i+1;j<=n;j++){
            if(check(i,j)>m) break;
            else ans=max(j-i+1,ans);
        }
    }
    cout<<ans;
    return 0;
}
