#include<bits/stdc++.h>
#define int long long
#define ll long long
#define pii pair<ll,ll>
using namespace std;
const int N=5e5+5;
string I_love_2c_s = "Forever";
int n,m,a[N],pot[N],b[N],li[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a+1,a+1+n);
    int l=unique(a+1,a+1+n)-a-1;
    for(int i=1;i<=n;i++){
        b[i]=lower_bound(a+1,a+1+l,b[i])-a;
        pot[b[i]]++;
    }
    int pt=1,cost=0,sig=pot[1],ans=pot[1];
    li[1]=pot[1];
    for(int i=2;i<=l;i++){
        cost += sig*(a[i]-a[i-1]);
        bool f=0;
        while(cost>m){
            int dx=a[i]-a[pt];
            if(dx*li[pt]>(cost-m)){
                sig -= (cost-m+dx-1)/dx;
                li[pt] -= (cost-m+dx-1)/dx;
                cost -= (cost-m+dx-1)/dx*dx;
            }else{
                cost-=dx*li[pt];
                sig-=li[pt];
                pt++;
            }
        }
        sig += pot[i];
        li[i] = pot[i];
        ans=max(ans,sig);
    }
    cout<<ans<<endl;
    return 0;
}
//37min pass all examples
//why I type wrong names but pass 3 examples...
