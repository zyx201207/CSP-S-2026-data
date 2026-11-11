#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
ll a[MAXN],s[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int l=1,ans=0;
    for(int r=1;r<=n;r++){
        while(s[r]-s[l]-(a[r]-a[l])*(l-1)>m)l++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
