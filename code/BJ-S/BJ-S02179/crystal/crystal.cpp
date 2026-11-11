#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m,a[N];

int find(long long x){
    return lower_bound(a+1,a+1+n,x)-a;
}

int check(long long x){
    int p=find(x);
    long long s=0,cnt=0;
    for(int i=p-1;i>=1;i--){
        if(s+(x-a[i])<=m){
            s+=(x-a[i]);
            cnt++;
        }
    }
    for(int i=p;i<=n;i++)if(a[i]==x)cnt++;
    return cnt;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool spA=1,d;
    for(int i=1;i<=n;i++)cin>>a[i];
    d=a[2]-a[1];
    for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=d)spA=0;
    if(spA==1){
        long long l,r;
        for(int i=1;i<=n;i++){
            l=n*(n-1)/2,r=n*(n+1)/2-1;
            if(l*d<=m&&m<=r*d){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+1+n);
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,check(a[i]));
    }
    cout<<ans;
    return 0;
}