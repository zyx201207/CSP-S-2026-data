#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500007],c[500007],s[500007],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    a[0]=0;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(ll i=1;i<=n;i++){
        s[i]=a[i];
        c[i]=a[i]-a[i-1];
    }
    ans=1;
    for(ll i=1;i<n;i++){
        if((s[ans+1]-s[1])*ans>m) break;
        else{
            m=m-(s[ans+1]-s[1])*ans;
            c[1]=s[ans+1];
            c[ans+1]=0;
            ans++;
        }
        for(ll i=1;i<=n;i++) s[i]=s[i-1]+c[i];
    }
    if(m) ans+=(s[ans+1]-s[1])/m;
    if(s[ans-1]==s[ans]) cout<<upper_bound(s+1,s+n+1,s[ans-1])-s-1;
    else cout<<ans-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
