#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,ans=0;
long long a[20010];
char c[20010];
int main(){
    freopen("string.in","r",stdin);
    freopen ("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    l=1;
    r=n;
    while ((r-l)>0){
        m=min(a[r],a[l]);
        a[r]-=m;
        a[l]-=m;
        if(c[l]!=c[r]) ans+=m;
        if(a[l]==0) l++;
        if(a[r]==0) r--;
    }
    cout<<ans;
    return 0;
}
