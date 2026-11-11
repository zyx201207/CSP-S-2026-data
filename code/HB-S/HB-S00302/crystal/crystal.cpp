#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,maxn,m,a[N],s[N];

bool cmp(long long x,long long y){
    return x<y;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=1;
    while(l<=r&&r<=n){
        long long len=r-l+1;
        long long c=1ll*a[r]*len-1ll*(s[r]-s[l-1]);
        if(c<=m){
            maxn=max(maxn,len);
            r++;
        }
        else{
            l++;
        }
    }
    cout<<maxn;
    return 0;
}
