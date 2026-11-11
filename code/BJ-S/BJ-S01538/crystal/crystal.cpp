#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
long long a[MAXN],s[MAXN];
long long n,m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    s[0]=0;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1,j=0;i<=n;i++){
        s[i]=s[i-1]+a[i];
        while(a[i]*(i-j)-s[i]+s[j]>m&&j<i) j++;
        ans=max(ans,i-j);
    }
    cout<<ans<<endl;
    return 0;
}
