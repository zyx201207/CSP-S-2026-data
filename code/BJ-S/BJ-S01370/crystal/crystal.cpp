#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],s[1000005],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==0){
        long long maxm=0;
        for(int i=1;i<=n;i++){
            s[a[i]]++;
            maxm=max(maxm,a[i]);
        }
        for(int i=1;i<=maxm;i++){
            ans=max(ans,a[s[i]]);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }

    for(long long i=1;i<=n;i++){
        long long x=i*a[i]-s[i];
        if(x<=m) ans=i;
    }
    cout<<ans;
    return 0;
}
