#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005];
long long s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=n,j=n;i>=1;i--){
        if(j>i) j=i;
        while(1){
            if(j<=0) break;
            int l=i-j+2;
            if((l-1)*a[i]-s[i-1]+s[j-2]>m) break;
            j-=1;
            ans=max(ans,i-j+1);
        }
    }
    cout<<ans;
    return 0;
}
