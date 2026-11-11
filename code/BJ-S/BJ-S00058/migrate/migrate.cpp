#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e6+65;
ll c,_,n,d,x[N];
void solvel(){
    int ans=1;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(ll i=1;i<=n;i++){
        ll j=1;
        j=max(i,j);
        while(j<=n and x[j+1]-x[i]<=d) j++;
        x[i]=j;
        cout<<x[i]<<" \n"[i==n];
    }
    for(ll i=1;i<=n;i++){
        ll j=x[i];
        while(j!=x[i]){
            if(j-i>1) ans+=x[j-1]-x[j-2];
            j=x[j];
        }
    }
    cout<<ans<<"\n";
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>_;
    for(int i=1;i<=_;i++) solvel();
    return 0;
}
