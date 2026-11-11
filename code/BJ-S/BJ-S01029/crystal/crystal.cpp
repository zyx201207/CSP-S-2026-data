#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000+2;
long long n,m,a[MAXN],x,l,ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    x=0ll;l=1ll;
    for(int i=1;i<=n;i++){
        while(l+1ll<=n&&(x+1ll*(l-i+1ll)*(a[l+1]-a[l]))<=m){
            x+=1ll*(l-i+1ll)*(a[l+1]-a[l]);
            l++;
        }
        if(x<=m)
            ans=max(ans,l-i+1ll);
        x-=a[l]-a[i];
    }
    cout<<ans<<endl;
}
