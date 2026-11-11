#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
const int N=5e5+10,INF=1e8;
ll a[N],g[N];
ll ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
       if(a[i]!=i)flag=1;
    }
    if(!flag){
            int maxx=a[n];
        for(int i=n;i;i--){
            if(m<maxx-a[i])break;
             ans++;
             m-=maxx-a[i];
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            g[j]=a[i]-a[j];
        }
        sort(g+1,g+1+i);
        ll f=m,j=1,sum=0;
        while(f>=g[j]&&j<=i){
            f-=g[j];
            sum++;
            j++;
        }
        ans=max(sum,ans);
        for(j=1;j<=i;j++)g[j]=0;
    }
    cout<<ans;

    return 0;
}
