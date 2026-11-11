#include<bits/stdc++.h>
long long x[2000005];
long long a[2000005],b[2000005],fa[2000005],fb[2000005];
long long c,t,n,d,ans;
using namespace std;
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1,j=1;i<=n;i++){
        while(x[j+1]<=x[i]+d&&j<n) j++;
        fa[i]=j;
    }
    for(int i=n;i>1;i--){
        if(fa[i]!=fa[i-1]&&fa[i]!=i){
            a[i]=fa[i]-fa[i-1]+a[fa[i]];
        }
    }
    for(int i=n,j=n;i>=1;i--){
        while(x[j-1]>=x[i]-d&&j>1) j--;
        fb[i]=j;
    }
    for(int i=1;i<n;i++){
        if(fb[i]!=fb[i+1]&&fb[i]!=i){
            b[i]=fb[i+1]-fb[i]+b[fb[i]];
        }
    }
    ans=0;
    for(int i=1;i<n;i++){
        if(fa[i]==fa[i-1]||fb[i+1]==fb[i+2]) continue;
        if(fa[i]<=i+1||fb[i+1]>=i) continue;
        if(fa[i]==fa[i+1]&&fb[i]==fb[i+1]) ans+=a[i]*b[i+1];
        else if(fa[i]==fa[i+1]) ans+=a[i]*(fb[i+2]-fb[i+1]);
        else if(fb[i]==fb[i+1]) ans+=b[i+1]*(fa[i]-fa[i-1]);
        else ans+=(fa[i]-fa[i-1])*(fb[i+2]-fb[i+1]);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        a[i]=0,b[i]=0,fa[i]=0,fb[i]=0,x[i]=0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
