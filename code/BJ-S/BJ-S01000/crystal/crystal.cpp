#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans;
bool f = 1;
int main(){
    freeopen("crystal.in","r",stdin);
    freeopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
        if(i>1&&a[i-1]>a[i]) f=0;
    }
    if(!f) sort(a+1,a+n+1);
    for(long long i = 1;i<=n;i++){
        long long tot = i*a[i];
        if(tot-s[i]<=m) ans = max(ans,i);
    }
    cout<<ans<<endl;
    return 0;
}