#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
ll n,m,a[maxn],d[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    /*for(int i=1;i<=n;++i){
        cout<<a[i];
    }*/
    for(int i=1;i<n;++i){
        d[i]=a[i+1]-a[i];
    }
    ll i=1,j=1,num=0,ans=0;
    while(1){
        //cout<<i<<' '<<a[i]<<endl;
        while((j<=n)&&(num<=m)){
            num+=d[j]*(j-i+1);
            //cout<<i<<' '<<j<<' '<<num<<endl;
            ++j;
        }
        --j;
        num-=d[j]*(j-i+1);
        num-=a[j]-a[i];
        //cout<<i<<' '<<j<<endl;
        ans=max(ans,j-i);
        if(j>=n){
            break;
        }
        ++i;
    }
    cout<<ans+1<<endl;
    return 0;
}
//100